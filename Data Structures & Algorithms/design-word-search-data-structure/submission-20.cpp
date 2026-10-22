class WordDictionary {
    struct Node {
        std::array<std::unique_ptr<Node>, 26> next;
        bool terminal = false;
    };

    Node root_;

public:    
    void addWord(std::string_view word) {
        Node* node = &root_;
        for (const char ch : word)
        {
            auto& child = node->next[slot(ch)];
            if (!child) {
                child = std::make_unique<Node>();
            }

            node = child.get();
        }

        node->terminal = true;
    }

    bool search(std::string_view word) const {
        const Node* n = find(&root_, word);
        return n != nullptr && n->terminal;
    }

private:
    static std::size_t slot(char ch) {
        return static_cast<std::size_t>(ch - 'a');
    }

    const Node* find(const Node* node, std::string_view str) const {
        if (!node)
            return nullptr;

        for (std::ptrdiff_t i = 0; i < std::ssize(str); ++i) {
            const char ch = str[i];
            if (ch == '.') {
                for (auto& n : node->next)
                {
                    if (!n) continue;

                    if (str.size() == i + 1)
                    {
                        if (!n->terminal) continue;

                        return n.get();
                    }

                    if (auto res = find(n.get(), str.substr(i + 1))) return res;
                }

                return nullptr;
            }

            node = node->next[slot(ch)].get();
            if (!node) return nullptr;
        }

        return node;
    }
};
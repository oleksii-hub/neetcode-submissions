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
        return match(&root_, word);
    }

private:
    static std::size_t slot(char ch) {
        return static_cast<std::size_t>(ch - 'a');
    }

    static bool match(const Node* node, std::string_view str) {
        for (std::size_t i = 0; i < str.size(); ++i) {
            if (str[i] == '.') {
                auto rest = str.substr(i + 1);
                for (const auto& child : node->next) {
                    if (child && match(child.get(), rest)) return true;
                }

                return false;
            }

            node = node->next[slot(str[i])].get();
            if (!node) return false;
        }

        return node->terminal;
    }
};
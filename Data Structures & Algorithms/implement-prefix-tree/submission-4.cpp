class PrefixTree {
public:
    void insert(std::string_view word) {
        Node* node = &root_;
        for (const char ch : word) {
            auto& child = node->next[slot(ch)];       // reference to the slot itself
            if (!child) child = std::make_unique<Node>();
            node = child.get();
        }
        node->terminal = true;
    }

    bool search(std::string_view word) const {
        const Node* n = find(word);
        return n != nullptr && n->terminal;
    }

    bool startsWith(std::string_view prefix) const {
        return find(prefix) != nullptr;
    }

private:
    struct Node {
        std::array<std::unique_ptr<Node>, 26> next;   // nullptr = no child
        bool terminal = false;
    };

    static std::size_t slot(char ch) {
        return static_cast<std::size_t>(ch - 'a');
    }

    const Node* find(std::string_view s) const {
        const Node* node = &root_;
        for (const char ch : s)
        {
            node = node->next[slot(ch)].get();
            if (!node) return nullptr;
        }
        return node;
    }

    Node root_;                                       // root by value: no allocation, never null
};
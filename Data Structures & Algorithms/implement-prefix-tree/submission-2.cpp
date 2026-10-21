class PrefixTree {
public:
    PrefixTree() { pool_.emplace_back(); }            // pool_[0] = root

    void insert(std::string_view word) {
        std::uint32_t cur = 0;
        for (const char ch : word)
        {
            const auto c = slot(ch);
            if (pool_[cur].next[c] == 0)
            {
                const auto child = static_cast<std::uint32_t>(pool_.size());
                pool_.emplace_back();                 // may reallocate — hold indices, not references
                pool_[cur].next[c] = child;           // link AFTER the child exists
            }
            cur = pool_[cur].next[c];
        }
        pool_[cur].terminal = true;
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
        std::array<std::uint32_t, 26> next{};         // 0 = no child (root is never a child)
        bool terminal = false;
    };

    static std::size_t slot(char ch) {
        return static_cast<std::size_t>(ch - 'a');
    }

    const Node* find(std::string_view s) const {
        std::uint32_t cur = 0;
        for (const char ch : s) {
            cur = pool_[cur].next[slot(ch)];
            if (cur == 0) return nullptr;
        }
        return &pool_[cur];
    }

    std::vector<Node> pool_;
};
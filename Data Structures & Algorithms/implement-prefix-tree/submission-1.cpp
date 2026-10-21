class PrefixTree {
private:
    struct Node {
        std::array<std::int32_t, 26> next{};
        bool terminal{};
    };

    std::vector<Node> pool;

    static std::size_t getIdx(char ch) {
        return ch - 'a';
    }

public:
    PrefixTree() {
        pool.emplace_back(Node{});
    }
    

    // dog
    // pool[0].next[d]=1
    // pool[1].next[o]=2
    // pool[2].next[g]=3
    // pool[3].terminal = true
    void insert(string word) {
        Node* node = &pool[0];
        std::size_t i = 0;
        while (i < word.size() && node->next[getIdx(word[i])] != 0)
        {
            node = &pool[node->next[getIdx(word[i])]];
            ++i;
        }

        if (i == word.size())
        {
            node->terminal = true;
            return;
        }

        std::int32_t idx = getIdx(word[i]);
        node->next[idx] = pool.size();
        ++i;
        while(i < word.size())
        {
            idx = getIdx(word[i]);
            Node newNode{};
            newNode.next[idx] = pool.size() + 1;
            pool.emplace_back(std::move(newNode));
            ++i;
        }

        Node terminalNode{};
        terminalNode.terminal = true;
        pool.emplace_back(std::move(terminalNode));
    }
    
    bool search(string word) {
        std::size_t i = 0;
        Node* node = &pool[0];
        while (i < word.size())
        {
            std::int32_t n = node->next[getIdx(word[i])];
            if (n == 0)
                return false;

            node = &pool[n];
            ++i;
        }

        return node->terminal;
    }
    
    bool startsWith(string prefix) {
        std::size_t i = 0;
        Node* node = &pool[0];
        while (i < prefix.size())
        {
            std::int32_t n = node->next[getIdx(prefix[i])];
            if (n == 0)
                return false;

            node = &pool[n];
            ++i;
        }

        return true;
    }
};

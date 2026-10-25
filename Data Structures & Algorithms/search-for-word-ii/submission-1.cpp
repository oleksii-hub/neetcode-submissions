class Solution {
    class TrieDictionary {
    private:
        struct Node {
            std::array<std::unique_ptr<Node>, 26> next;
            const std::string* word{ nullptr };
        };

    public:
        TrieDictionary(
            const std::vector<std::vector<char>>& board,
            const std::vector<std::string>& words)
            : board_(board), words_(words)
        {
            for (const auto& word : words_)
                add(word);
        }

        void add(const std::string& word) {
            Node* node = &root_;
            for (const char ch : word) {
                auto& child = node->next[slot(ch)];
                if (!child) child = std::make_unique<Node>();

                node = child.get();
            }

            node->word = &word;
        }

        std::vector<std::string> findWords() {
            result.clear();

            for (int r = 0; r < rows(); ++r) {
                for (int c = 0; c < columns(); ++c) {
                    auto& child = root_.next[slot(board_[r][c])];
                    if (child)
                    {
                        dfs(r, c, child.get());
                    }
                }
            }

            return result;
        }

        void dfs(int r, int c, Node* node) {
            if (node->word != nullptr)
            {
                result.emplace_back(*node->word);
                node->word = nullptr;
            }

            visited[r * columns() + c] = true;

            for (const auto [dr, dc] : kDirs) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr < 0 || nc < 0 || nr >= rows() || nc >= columns()) {
                    continue;
                }

                if (visited[nr * columns() + nc])
                    continue;

                auto& child = node->next[slot(board_[nr][nc])];
                if (!child) {
                    continue;
                }

                dfs(nr, nc, child.get());

                if (!hasChildren(*child.get()))
                {
                    child.reset();
                }
            }

            visited[r * columns() + c] = false;
        }

    private:
        static std::size_t slot(char ch) {
            return static_cast<std::size_t>(ch - 'a');
        }

        static bool hasChildren(const Node& node) {
            for (const auto& child : node.next) {
                if (child) return true;
            }

            return false;
        }

        int rows() const {
            return static_cast<int>(board_.size());
        }

        int columns() const {
            return static_cast<int>(board_.at(0).size());
        }

        static constexpr std::array<std::pair<int, int>, 4> kDirs
            {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

        Node root_;
        std::array<bool, 144> visited;
        std::vector<std::string> result;
        const std::vector<std::vector<char>>& board_;
        const std::vector<std::string>& words_;
    };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieDictionary trie(board, words);
        return trie.findWords();
    }
};

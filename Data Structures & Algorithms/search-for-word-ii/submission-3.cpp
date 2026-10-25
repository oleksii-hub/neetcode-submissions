#include <array>
#include <cassert>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board,
                                       std::vector<std::string>& words) {
        Node root;
        for (const auto& w : words)
            insert(root, w);

        Search s{board, static_cast<int>(board.size()), static_cast<int>(board[0].size())};

        for (int r = 0; r < s.rows && root.children > 0; ++r) { // stop once all words are found
            for (int c = 0; c < s.cols && root.children > 0; ++c) {
                auto& child = root.next[slot(board[r][c])];
                if (!child) continue;

                s.dfs(r, c, *child);

                if (child->children == 0) { // word already cleared by dfs
                    child.reset();
                    --root.children;
                }
            }
        }

        return std::move(s.found);
    }

private:
    static constexpr int kMaxCells = 12 * 12;

    struct Node {
        std::array<std::unique_ptr<Node>, 26> next;
        const std::string* word = nullptr;   // non-null: an unreported word ends here
        int children = 0;
    };

    static std::size_t slot(char ch) {
        assert(ch >= 'a' && ch <= 'z');
        return static_cast<std::size_t>(ch - 'a');
    }

    static void insert(Node& root, const std::string& w) {   // w must outlive the search
        Node* node = &root;

        for (const char ch : w) {
            auto& child = node->next[slot(ch)];
            if (!child) {
                child = std::make_unique<Node>();
                ++node->children;
            }

            node = child.get();
        }
        node->word = &w;
    }

    struct Search {
        const std::vector<std::vector<char>>& board;
        int rows;
        int cols;
        std::array<bool, kMaxCells> visited{}; // value-initialized
        std::vector<std::string> found;

        static constexpr std::array<std::pair<int, int>, 4> kDirs{{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

        void dfs(int r, int c, Node& node) {
            if (node.word) { // record + clear: first, unconditionally
                found.push_back(*node.word);
                node.word = nullptr;
            }

            visited[r * cols + c] = true;

            for (const auto [dr, dc] : kDirs) {
                const int nr = r + dr;
                const int nc = c + dc;
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                    continue;

                if (visited[nr * cols + nc])
                    continue;

                auto& child = node.next[slot(board[nr][nc])];
                if (!child)
                    continue;

                dfs(nr, nc, *child);

                if (child->children == 0) { // post-order prune; word cleared on entry
                    child.reset();
                    --node.children;
                }

                if (node.children == 0) break; // nothing left below this node
            }

            visited[r * cols + c] = false;
        }
    };
};
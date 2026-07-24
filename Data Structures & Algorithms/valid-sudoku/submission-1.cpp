class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        static const std::size_t size = 9;
        static const std::size_t gridSize = 3;
        if (board.size() != size)
            return false;

        std::unordered_set<char> rowSet;
        std::array<std::unordered_set<char>, 9> columnSet;
        std::array<std::unordered_set<char>, gridSize> gridSet;
        for (std::size_t i = 0; i < size; ++i)
        {
            if (board[i].size() != size)
                return false;

            for (std::size_t j = 0; j < size; ++j)
            {
                if (board[i][j] == '.')
                    continue;

                int num = 0;
                std::from_chars(&board[i][j], &board[i][j] + 1, num);
                if (num <= 0 || num >= 10)
                    return false;

                auto existsRow = rowSet.insert(board[i][j]);
                if (!existsRow.second) return false;

                int idx = j / gridSize;
                auto existsGrid = gridSet[idx].insert(board[i][j]);
                if (!existsGrid.second) return false;

                auto existsCol = columnSet[j].insert(board[i][j]);
                if (!existsCol.second) return false;
            }

            if (i == 2 || i == 5)
            {
                gridSet[0].clear();
                gridSet[1].clear();
                gridSet[2].clear();
            }

            rowSet.clear();
        }

        return true;
    }
};

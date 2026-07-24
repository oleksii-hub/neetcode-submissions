class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::array<std::uint32_t, 9> rows{}, cols{}, boxes{};

        for (std::size_t r = 0; r < board.size(); ++r)
        {
            for (std::size_t c = 0; c < board.size(); ++c)
            {
                char ch = board[r][c];
                if (ch == '.') continue;

                int num = ch - '0';

                std::uint32_t bit = 1u << num;
                const int boxIdx = (r / 3) * 3 + c / 3;
                if ((rows[r] | cols[c] | boxes[boxIdx]) & bit)
                    return false;

                rows[r] |= bit;
                cols[c] |= bit;
                boxes[boxIdx] |= bit;
            }
        } 

        return true;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        std::ptrdiff_t lo = 0;
        std::ptrdiff_t hi = std::ssize(matrix);
        std::ptrdiff_t rowIdx = 0;

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;
            if (target >= matrix[mid].front() && target <= matrix[mid].back())
            {
                rowIdx = mid;
                break;
            }

            if (matrix[mid].back() > target)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        auto& targetRow = matrix[rowIdx];
        lo = 0;
        hi = std::ssize(targetRow);

        while(lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;
            if (targetRow[mid] == target)
                return true;

            if (targetRow[mid] > target)
                hi = mid;
            else
                lo = mid + 1;
        }

        return false;
    }
};

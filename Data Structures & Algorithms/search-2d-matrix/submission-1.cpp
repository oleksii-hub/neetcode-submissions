class Solution {
public:
    bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
        const auto rows = std::ssize(matrix);
        const auto cols = std::ssize(matrix[0]);

        std::ptrdiff_t lo = 0;
        std::ptrdiff_t hi = rows * cols;

        while (lo < hi) {
            const auto mid = lo + (hi - lo) / 2;
            const int value = matrix[mid / cols][mid % cols];

            if (value >= target) { hi = mid; }
            else { lo = mid + 1; }
        }

        return lo < rows * cols && matrix[lo / cols][lo % cols] == target;
    }
};
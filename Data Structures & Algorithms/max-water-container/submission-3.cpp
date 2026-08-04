class Solution {
public:
    int maxArea(const std::vector<int>& heights) {
        std::ptrdiff_t left = 0;
        std::ptrdiff_t right = std::ssize(heights) - 1;

        std::ptrdiff_t best = 0;

        while (left < right) {
            const auto area = (right - left) * std::min(heights[left], heights[right]);
            best = std::max(best, area);

            if (heights[left] < heights[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return static_cast<int>(best);
    }
};
class Solution {
public:
    int trap(const std::vector<int>& height) {
        const auto n = std::ssize(height);
        const auto peak = std::ranges::max_element(height) - height.begin();

        int total = 0;

        int runningMax = 0;
        for (std::ptrdiff_t i = 0; i < peak; ++i) {
            runningMax = std::max(runningMax, height[i]);
            total += runningMax - height[i];
        }

        runningMax = 0;
        for (std::ptrdiff_t i = n - 1; i > peak; --i) {
            runningMax = std::max(runningMax, height[i]);
            total += runningMax - height[i];
        }

        return total;
    }
};

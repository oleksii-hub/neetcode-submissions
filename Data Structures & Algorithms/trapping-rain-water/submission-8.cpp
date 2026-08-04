class Solution {
public:
    int trap(const std::vector<int>& height) {
        std::ptrdiff_t left = 0;
        std::ptrdiff_t right = std::ssize(height) - 1;

        int leftMax = height[left];
        int rightMax = height[right];
        int total = 0;

        while (left < right) {
            if (leftMax <= rightMax) {
                ++left;
                leftMax = std::max(leftMax, height[left]);
                total += leftMax - height[left];
            } else {
                --right;
                rightMax = std::max(rightMax, height[right]);
                total += rightMax - height[right];
            }
        }

        return total;
    }
};

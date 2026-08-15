class Solution {
public:
    int search(const std::vector<int>& nums, int target) {
        std::ptrdiff_t lo = 0;
        std::ptrdiff_t hi = std::ssize(nums) - 1;

        while (lo <= hi) {
            const auto mid = lo + (hi - lo) / 2;

            if (nums[mid] == target) {
                return static_cast<int>(mid);
            }

            if (nums[lo] <= nums[mid]) {          // left half sorted
                if (nums[lo] <= target && target < nums[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else {                               // right half sorted
                if (nums[mid] < target && target <= nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }

        return -1;
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 9, 10, 1, 2, 3, 4, 5, 6, 7, 8
        // 3, 4, 5, 6, 7, 8, 9, 10, 1, 2

        std::ptrdiff_t lo = 0;
        std::ptrdiff_t hi = std::ssize(nums) - 1;
        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[hi] < nums[mid])
            {
                if (nums[mid] >= target && nums[hi] < target)
                    hi = mid;
                else lo = mid + 1;
            }
            else if (nums[mid] < nums[lo])
            {
                if (nums[mid] >= target || nums[lo] <= target)
                    hi = mid;
                else lo = mid + 1;
            }
            else
            {
                if (nums[mid] >= target)
                    hi = mid;
                else lo = mid + 1;
            }
        }

        if (lo < std::ssize(nums) && nums[lo] == target)
            return static_cast<int>(lo);

        return -1;
    }
};

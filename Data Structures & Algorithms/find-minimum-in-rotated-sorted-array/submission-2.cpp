class Solution {
public:
    int findMin(vector<int> &nums) {
        std::ptrdiff_t lo = 0;
        std::ptrdiff_t hi = std::ssize(nums) - 1;
        while(lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[hi])
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return nums[lo];
    }
};

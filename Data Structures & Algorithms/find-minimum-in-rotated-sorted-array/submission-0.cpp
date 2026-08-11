class Solution {
public:
    int findMin(vector<int> &nums) {
        // 3, 4, 5, 6, 7, 8, 9, 10, 1, 2
        // 9, 10, 1, 2, 3, 4, 5, 6, 7, 8
        // 1, 2, 3, 4, 5 ,6 ,7 ,8 ,9, 10
        // 6, 7, 8, 9, 10, 1, 2, 3, 4, 5

        std::ptrdiff_t lo = 0;
        std::ptrdiff_t hi = std::ssize(nums) - 1;
        while(lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[lo])
            {
                hi = mid;
            }
            else if (nums[mid] > nums[hi])
            {
                lo = mid + 1;
            }
            else
            {
                break;
            }
        }

        return nums[lo];
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = static_cast<int>(nums.size());

        while (lo < hi)
        {
            auto mid = lo + (hi - lo) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                hi = mid;
            else
                lo = mid + 1;
        }

        return -1;
    }
};

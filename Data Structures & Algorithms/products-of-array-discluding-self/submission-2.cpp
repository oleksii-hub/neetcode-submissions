class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroIdx = -1;
        int target = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                if (zeroIdx != -1)
                {
                    return std::vector<int>(nums.size(), 0);
                }

                zeroIdx = i;
                continue;
            }

            target *= nums[i];
        }
        
        std::vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (zeroIdx != -1)
            {
                result[i] = zeroIdx != i ? 0 : target;
                continue;
            }

            result[i] = target / nums[i];
        }

        return result;
    }
};

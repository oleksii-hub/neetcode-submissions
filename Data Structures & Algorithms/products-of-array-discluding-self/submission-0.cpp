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
        
        std::vector<int> result;
        result.reserve(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (zeroIdx != -1)
            {
                if (i != zeroIdx)
                    result.push_back(0);
                else
                    result.push_back(target);

                continue;
            }

            result.push_back(target / nums[i]);
        }

        return result;
    }
};

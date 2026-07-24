class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroIdx = -1;
        int target = 1;
        vector<int> prefixes(nums.size());
        vector<int> suffixes(nums.size());
        
        int product = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                prefixes[i] = 1;
                continue;
            }

            product *= nums[i - 1];
            prefixes[i] = product;
        }

        product = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (i == nums.size() - 1)
            {
                suffixes[i] = 1;
                continue;
            }

            product *= nums[i + 1];
            suffixes[i] = product;
        }
        
        std::vector<int> result;
        result.reserve(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            result.push_back(prefixes[i] * suffixes[i]);
        }

        return result;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.empty())
            return {};

        std::unordered_map<int, int> numsMap;

        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            const auto& it = numsMap.find(diff);
            if (it != numsMap.end())
                return {it->second, i};
            
            numsMap[nums[i]] = i;
        }

        return {};
    }
};

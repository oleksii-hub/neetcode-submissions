class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> numsToCount;
        for (int i = 0; i < nums.size(); i++)
        {
            numsToCount[nums[i]]++;
        }

        std::vector<std::vector<int>> freq(nums.size() + 1);

        for (const auto& entry : numsToCount)
            freq[entry.second].push_back(entry.first);

        std::vector<int> res;
        for (int i = freq.size() - 1; i > 0; i--)
        {
            for (int num : freq[i])
            {
                res.push_back(num);
                if (res.size() == k)
                    return res;
            }
        }

        return res;
    }
};
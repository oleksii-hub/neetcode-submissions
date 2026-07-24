class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if (nums.empty())
            return false;

        std::set<int> seen;
        for (int i : nums)
        {
            if (seen.find(i) != seen.end())
                return true;
            else
                seen.insert(i);
        }

        return false;
    }
};
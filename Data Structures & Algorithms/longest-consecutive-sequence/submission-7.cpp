#include <ranges>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        std::unordered_set<int> numsSet(nums.begin(), nums.end());

        int streak = 1;
        int bestStreak = 1;
        for (int num : numsSet)
        {
            if (!numsSet.contains(num - 1))
            {
                int len = 1;
                while(numsSet.contains(num + len))
                {
                    ++len;
                }

                bestStreak = std::max(bestStreak, len);
            }
        }

        return bestStreak;
    }
};

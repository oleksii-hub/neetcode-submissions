#include <ranges>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        std::set<int> numsSet(nums.begin(), nums.end());

        int streak = 1;
        int bestStreak = 1;
        int prev = *numsSet.begin();
        for (int num : numsSet | std::ranges::views::drop(1))
        {
            if (num == prev + 1)
            {
                ++streak;
            }
            else if (num != prev)
            {
                streak = 1;
            }

            if (streak > bestStreak)
                bestStreak = streak;

            prev = num;
        }

        return bestStreak;
    }
};

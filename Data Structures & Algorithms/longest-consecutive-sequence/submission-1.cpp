class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        std::ranges::sort(nums);
        int streak = 1;
        int bestStreak = 1;
        int prev = nums[0];
        for (std::size_t i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == prev + 1)
            {
                ++streak;
            }
            else if (nums[i] != prev)
            {
                streak = 1;
            }

            if (streak > bestStreak)
                bestStreak = streak;

            prev = nums[i];
        }

        return bestStreak;
    }
};

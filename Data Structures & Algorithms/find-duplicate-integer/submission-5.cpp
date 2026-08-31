class Solution {
public:
    // size: 5, [1,4]
    // 2, 6, 5, 7, 2, 3, 4, 1
    // 0 -> 2 - > 5 -> 3 -> 7 -> 1 -> 5 -> 4 -> 2
    int findDuplicate(std::vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while (slow != fast);

        int slowSecond = 0;
        while (slow != slowSecond)
        {
            slow = nums[slow];
            slowSecond = nums[slowSecond];
        }

        return slow;
    }
};
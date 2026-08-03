class Solution {
public:
    vector<int> twoSum(const std::vector<int>& numbers, int target) {
        int left = 0;
        int right = static_cast<int>(numbers.size());
        while (left < right)
        {
            int sum = numbers[left] + numbers[right - 1];
            if (sum == target)
                return {left + 1, right};

            if (sum > target)
                --right;
            else if (sum < target)
                ++left;
        }

        return {};
    }
};

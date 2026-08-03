class Solution {
public:
    vector<int> twoSum(const std::vector<int>& numbers, int target) {
        if (numbers.empty())
            return {};

        std::size_t left = 0;
        std::size_t right = numbers.size();
        while (left < right)
        {
            int sum = numbers[left] + numbers[right - 1];
            if (sum == target)
                return {static_cast<int>(left) + 1, static_cast<int>(right)};

            if (sum > target)
                --right;
            else if (sum < target)
                ++left;
        }

        return {};
    }
};

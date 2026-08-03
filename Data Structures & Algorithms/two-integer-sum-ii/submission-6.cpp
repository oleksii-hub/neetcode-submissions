class Solution {
public:
    vector<int> twoSum(const std::vector<int>& numbers, int target) {
        std::size_t left = 0;
        std::size_t right = numbers.size() - 1;
        while (left < right)
        {
            const int sum = numbers[left] + numbers[right];
            if (sum == target)
                return {static_cast<int>(left) + 1, static_cast<int>(right) + 1};

            if (sum > target)
                --right;
            else
                ++left;
        }

        return {};
    }
};

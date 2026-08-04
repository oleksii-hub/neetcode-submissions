class Solution {
public:
    vector<vector<int>> threeSum(const vector<int>& nums) {
        if (nums.empty())
            return {};

        auto sorted = nums;
        std::ranges::sort(sorted);

        std::set<std::vector<int>> result;
        std::ptrdiff_t n = std::ssize(sorted);
        for (std::ptrdiff_t i = 0; i < n - 2; ++i)
        {
            if (sorted[i] > 0)
                break;

            std::ptrdiff_t left = i + 1;
            std::ptrdiff_t right = n - 1;

            while (left < right)
            {
                int sum = sorted[left] + sorted[right];
                if (sum + sorted[i] == 0)
                {
                    result.insert({sorted[i], sorted[left], sorted[right]});
                    --right;
                    continue;
                }

                if (sum + sorted[i] < 0)
                {
                    ++left;
                    continue;
                }

                --right;
            }
        }

        return std::vector(result.begin(), result.end());
    }
};

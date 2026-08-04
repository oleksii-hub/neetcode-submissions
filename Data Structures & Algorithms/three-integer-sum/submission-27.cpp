class Solution {
public:
    vector<vector<int>> threeSum(const std::vector<int>& nums) {
        auto sorted = nums;
        std::ranges::sort(sorted);

        std::vector<std::vector<int>> result;
        std::ptrdiff_t n = std::ssize(sorted);
        for (std::ptrdiff_t i = 0; i < n - 2; ++i)
        {
            if (sorted[i] > 0)
                break;

            if (i > 0 && sorted[i] == sorted[i - 1])
                continue;

            std::ptrdiff_t left = i + 1;
            std::ptrdiff_t right = n - 1;

            while (left < right)
            {
                int sum = sorted[left] + sorted[right];
                if (sum + sorted[i] == 0)
                {
                    result.push_back({sorted[i], sorted[left], sorted[right]});

                    --right;
                    ++left;

                    while (left < right && sorted[left] == sorted[left - 1])
                        ++left;

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

        return result;
    }
};

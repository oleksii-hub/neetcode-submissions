class Solution {
public:
    vector<vector<int>> threeSum(std::vector<int>& nums) {
        std::ranges::sort(nums);

        std::vector<std::vector<int>> result;
        std::ptrdiff_t n = std::ssize(nums);
        for (std::ptrdiff_t i = 0; i < n - 2; ++i)
        {
            if (nums[i] > 0)
                break;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            std::ptrdiff_t left = i + 1;
            std::ptrdiff_t right = n - 1;

            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum + nums[i] == 0)
                {
                    result.push_back({nums[i], nums[left], nums[right]});

                    --right;
                    ++left;

                    while (left < right && nums[left] == nums[left - 1])
                        ++left;

                    continue;
                }

                if (sum + nums[i] < 0)
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

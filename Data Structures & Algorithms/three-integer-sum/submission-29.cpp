class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::ranges::sort(nums);

        std::vector<std::vector<int>> result;
        const std::ptrdiff_t n = std::ssize(nums);

        for (std::ptrdiff_t i = 0; i < n - 2; ++i) {
            const int first = nums[i];

            if (first > 0) {
                break;
            }

            if (i > 0 && first == nums[i - 1]) {
                continue;
            }

            std::ptrdiff_t left = i + 1;
            std::ptrdiff_t right = n - 1;

            while (left < right) {
                const int sum = first + nums[left] + nums[right];

                if (sum < 0) {
                    ++left;
                } else if (sum > 0) {
                    --right;
                } else {
                    result.push_back({first, nums[left], nums[right]});

                    ++left;
                    --right;

                    while (left < right && nums[left] == nums[left - 1]) {
                        ++left;
                    }
                }
            }
        }

        return result;
    }
};
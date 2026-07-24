class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        const std::size_t n = nums.size();
        std::vector<int> result(n);

        int prefix = 1;
        for (std::size_t i = 0; i < n; ++i) {
            result[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (std::size_t i = n; i-- > 0; ) {
            result[i] *= suffix;
            suffix *= nums[i];
        }

        return result;
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;

        const std::size_t n = nums.size();
        std::size_t count = 1;
        for (std::size_t k = 2; k <= n; ++k)
            count *= k;

        result.reserve(count);
        path.reserve(n);

        auto dfs = [&] (this auto& self, std::uint32_t used) -> void
        {
            if (path.size() == n) {
                result.push_back(path);
                return;
            }

            for(std::size_t i = 0; i < n; ++i) {
                const auto bit = 1u << i;
                if (used & bit) continue;
                
                path.push_back(nums[i]);
                self(used | bit);
                path.pop_back();
            }
        };

        dfs(0u);

        return result;
    }
};

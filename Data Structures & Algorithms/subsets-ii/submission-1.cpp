class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::ranges::sort(nums);

        std::vector<std::vector<int>> result;
        std::vector<int> path;
        std::size_t n = nums.size();

        result.reserve(std::size_t{1u} << n);
        path.reserve(n);

        auto dfs = [&](this auto& self, std::size_t start) -> void {
            result.push_back(path);

            for(std::size_t i = start; i < n; ++i) {
                if (i > start && nums[i] == nums[i - 1]) continue;

                path.push_back(nums[i]);
                self(i + 1);
                path.pop_back();
            }
        };

        dfs(0);

        return result;
    }
};

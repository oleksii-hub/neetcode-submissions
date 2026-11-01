class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::ranges::sort(nums);

        std::vector<vector<int>> result;
        std::vector<int> path;
        path.reserve(static_cast<std::size_t>(target / nums.front()));

        auto dfs = [&] (this auto& self, std::size_t start, int remaining) -> void {
            if (remaining == 0) {
                result.push_back(path);
                return;
            }

            for (std::size_t i = start; i < nums.size(); ++i) {
                if (nums[i] > remaining) break;

                path.push_back(nums[i]);
                self(i, remaining - nums[i]);
                path.pop_back();
            }
        };

        dfs(0, target);

        return result;
    }
};

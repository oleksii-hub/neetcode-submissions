class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<vector<int>> result;
        std::vector<int> path;

        result.reserve(std::size_t{1} << nums.size());
        path.reserve(nums.size());

        auto dfs = [&] (this auto& self, std::size_t start, int remaining) -> void {
            if (remaining == 0) {
                result.push_back(path);
                return;
            }

            for (std::size_t i = start; i < nums.size(); ++i) {
                if (nums[i] > remaining) continue;

                path.push_back(nums[i]);
                self(i, remaining - nums[i]);
                path.pop_back();
            }
        };

        dfs(0, target);

        return result;
    }
};

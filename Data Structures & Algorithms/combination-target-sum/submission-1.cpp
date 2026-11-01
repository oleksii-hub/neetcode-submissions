class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<vector<int>> result;
        std::vector<int> path;

        result.reserve(std::size_t{1} << nums.size());
        path.reserve(nums.size());

        auto dfs = [&] (this auto& self, std::size_t start) -> void {
            int sum = 0;
            for (auto v : path) {
                sum += v;
            }

            if (sum == target) {
                result.push_back(path);
                return;
            }

            for (std::size_t i = start; i < nums.size(); ++i) {
                if (sum + nums[i] > target) continue;

                path.push_back(nums[i]);
                self(i);
                path.pop_back();
            }
        };

        dfs(0);

        return result;
    }
};

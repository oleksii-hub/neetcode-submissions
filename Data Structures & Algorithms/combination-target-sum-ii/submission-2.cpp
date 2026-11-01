class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::ranges::sort(candidates);

        std::vector<std::vector<int>> result;
        std::vector<int> path;

        path.reserve(candidates.size());

        auto dfs = [&] (this auto& self, std::size_t start, int remaining) -> void {
            if (remaining == 0) {
                result.push_back(path);
                return;
            }

            // 1, 2, 2, 4, 5, 6, 9
            for (std::size_t i = start; i < candidates.size(); ++i) {
                if (candidates[i] > remaining) break;

                if(i > start && candidates[i] == candidates[i - 1]) continue;

                path.push_back(candidates[i]);
                self(i + 1, remaining - candidates[i]);
                path.pop_back();
            }
        };

        dfs(0, target);

        return result;
    }
};

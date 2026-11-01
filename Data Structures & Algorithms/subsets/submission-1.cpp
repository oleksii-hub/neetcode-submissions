class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        result.reserve(std::size_t{1} << nums.size());
        std::vector<int> path;
        path.reserve(nums.size());

        auto dfs = [&](this auto& self, std::size_t start) -> void {
            result.push_back(path);                       // every node is an answer
            for (std::size_t i = start; i < nums.size(); ++i) {
                path.push_back(nums[i]);                  // choose
                self(i + 1);                              // explore
                path.pop_back();                          // unchoose
            }
        };
        dfs(0);
        return result;
    }
};
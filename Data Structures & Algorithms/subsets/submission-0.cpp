class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        SubsetsFinder finder(nums);
        finder.dfs(0);
        return std::move(finder.result);
    }

private:
    struct SubsetsFinder
    {
        std::vector<vector<int>> result;
        const std::vector<int>& nums;

        SubsetsFinder(const std::vector<int>& nums_) 
            : nums(nums_) {}

        void dfs(std::size_t start) {
            result.push_back(path);
            for (std::size_t i = start; i < nums.size(); ++i) {
                path.push_back(nums[i]);
                dfs(i + 1);
                path.pop_back();
            }
        }

    private:
        std::vector<int> path;
    };
};

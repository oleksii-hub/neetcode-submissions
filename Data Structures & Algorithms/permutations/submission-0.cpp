class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;

        result.reserve(std::size_t{1} << nums.size());
        path.reserve(nums.size());
        std::uint32_t used = 0;

        auto dfs = [&] (this auto& self) -> void
        {
            if (path.size() == nums.size()) {
                result.push_back(path);
                return;
            }

            for(std::size_t i = 0; i < nums.size(); ++i) {
                if (used & (std::uint32_t{1u} << i)) continue;
                
                used |= (std::uint32_t{1u} << i);
                path.push_back(nums[i]);
                self();
                path.pop_back();
                used &= ~(std::uint32_t{1u} << i);
            }
        };

        dfs();

        return result;
    }
};

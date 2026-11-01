class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> result{{}};
        for (const int x : nums) {
            const std::size_t sz = result.size();             // snapshot: don't iterate what you're appending
            for (std::size_t j = 0; j < sz; ++j) {
                auto copy = result[j];                         // copy first: result[j] may move on reallocation
                copy.push_back(x);
                result.push_back(std::move(copy));
            }
        }

        return result;
    }
};

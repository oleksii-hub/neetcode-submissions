class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty())
            return {};
        
        std::unordered_map<std::string, std::vector<std::string>> seen;
        for (int i = 0; i < strs.size(); i++)
        {
            std::string strSorted = strs[i];
            std::ranges::sort(strSorted);
            seen[strSorted].push_back(strs[i]);
        }

        std::vector<std::vector<std::string>> result;
        for (const auto& keyValue : seen)
        {
            result.push_back(keyValue.second);
        }

        return result;
    }
};

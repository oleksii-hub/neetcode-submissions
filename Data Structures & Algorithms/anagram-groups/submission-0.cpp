class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty())
            return {};
        
        std::vector<std::vector<std::string>> result;
        std::unordered_map<std::string, int> seen;
        for (int i = 0; i < strs.size(); i++)
        {
            std::string strSorted = strs[i];
            std::ranges::sort(strSorted);
            auto it = seen.find(strSorted);
            if (it != seen.end())
            {
                auto& vec = result[it->second];
                vec.push_back(strs[i]);
            }
            else
            {
                result.push_back({strs[i]});
                seen[strSorted] = result.size() - 1;
            }
        }

        return result;
    }
};

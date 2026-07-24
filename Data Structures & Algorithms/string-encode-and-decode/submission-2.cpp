class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty())
            return {};

        std::string result;
        for (const auto& str : strs)
        {
            result += std::to_string(str.size());
            result += '#';
            result += str;
        }

        return result;
    }

    vector<string> decode(string s) {
        if (s.empty())
            return {};

        std::vector<std::string> result;

        std::string word;
        int i = 0;
        while (i < s.size())
        {
            int j = i;
            while (s[j] != '#')
            {
                j++;
            }

            int len = stoi(s.substr(i, j - i));
            i = j + 1;
            result.push_back(s.substr(i, len));
            i += len;
        }

        return result;
    }
};

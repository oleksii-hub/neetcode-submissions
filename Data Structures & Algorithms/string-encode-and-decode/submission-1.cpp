class Solution {
public:

    string encode(vector<string>& strs) {
        char delimiter = 0;
        std::string result;
        for (const auto& str : strs)
        {
            for (char ch : str)
            {
                result += ch;
            }

            result += delimiter;
        }

        return result;
    }

    vector<string> decode(string s) {
        std::vector<std::string> result;
        char delimiter = 0;

        std::string word;
        for (char ch : s)
        {
            if (ch == delimiter)
            {
                result.push_back(word);
                word.clear();
                continue;
            }

            word += ch;
        }

        return result;
    }
};

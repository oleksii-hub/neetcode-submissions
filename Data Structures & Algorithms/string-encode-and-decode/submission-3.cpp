class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty())
            return {};

        std::size_t total;
        for (const auto& str : strs) total += str.size() + 4;

        std::string result;
        result.reserve(total);
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

        int i = 0;
        while (i < s.size())
        {
            const std::size_t hashtag = s.find('#', i);
            std::size_t len = 0;
            std::from_chars(s.data() + i, s.data() + hashtag, len);
            i = hashtag + 1;
            result.emplace_back(s, i, len);
            i += len;
        }

        return result;
    }
};

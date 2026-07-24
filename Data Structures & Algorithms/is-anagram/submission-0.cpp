class Solution {
public:
    bool isAnagram(string s, string t) {
        std::ranges::sort(s);
        std::ranges::sort(t);

        return s == t;
    }
};

class Solution {
public:
    bool isValid(std::string_view s) {
        if (s.size() % 2 != 0) return false;          // odd length can't balance

        std::vector<char> st;
        st.reserve(s.size() / 2);

        for (const char ch : s) {
            switch (ch) {
                case '(': st.push_back(')'); break;
                case '[': st.push_back(']'); break;
                case '{': st.push_back('}'); break;
                default:
                    if (st.empty() || st.back() != ch) return false;
                    st.pop_back();
            }
        }
        return st.empty();
    }
};

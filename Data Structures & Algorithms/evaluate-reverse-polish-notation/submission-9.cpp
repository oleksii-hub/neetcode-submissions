class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::vector<int> st;
        st.reserve(tokens.size() / 2 + 1);

        for(const std::string_view tok : tokens)
        {
            char c = tok.front();
            if (tok.size() != 1 || (c >= '0' && c <= '9'))
            {
                int num;
                std::from_chars(tok.data(), tok.data() + tok.size(), num);
                st.push_back(num);
                continue;
            }

            const int b = st.back();
            st.pop_back();
            int& a = st.back();
            switch(c)
            {
                case '+': a += b; break;
                case '-': a -= b; break;
                case '*': a *= b; break;
                case '/': a /= b; break;
            }
        }

        return st.back();
    }
};

class Solution {
public:
    bool isValid(string s) {
        std::pair<char, char> round {'(', ')'};
        std::pair<char, char> curly {'{', '}'};
        std::pair<char, char> square {'[', ']'};

        std::stack<char> st;
        for (const char ch : s)
        {
            if (ch == round.second)
            {
                if (st.empty() || round.first != st.top())
                    return false;

                st.pop();
                continue;
            }
            else if (ch == curly.second)
            {
                if (st.empty() || curly.first != st.top())
                    return false;

                st.pop();
                continue;
            }
            else if (ch == square.second)
            {
                if (st.empty() || square.first != st.top())
                    return false;

                st.pop();
                continue;
            }

            st.push(ch);
        }

        return st.empty();
    }
};

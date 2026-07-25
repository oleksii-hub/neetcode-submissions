class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for (const char ch : s)
        {
            bool isSquare = ch == ']';
            bool isRound = ch == ')';
            bool isCurly = ch == '}';
            bool isClosing = isSquare || isRound || isCurly;
            if (!isClosing)
            {
                st.push(ch);
                continue;
            }

            char closing = isSquare ? '[' :
                (isRound ? '(' : '{');

            if (st.empty() || st.top() != closing)
                return false;

            st.pop();
        }

        return st.empty();
    }
};

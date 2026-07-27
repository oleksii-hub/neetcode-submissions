class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty())
            return 0;

        int result = 0;
        std::stack<int, std::vector<int>> st;        
        for (const auto& str : tokens)
        {
            bool isPlus = str == "+";
            bool isMinus = str == "-";
            bool isMult = str == "*";
            bool isDiv = str == "/";

            if (!isPlus && !isMinus && !isMult && !isDiv)
            {
                int num;
                std::from_chars(str.data(), str.data() + str.size(), num);
                st.push(num);
                continue;
            }

            if (st.size() < 2)
                return 0;

            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();
            int result;
            if (isPlus)
                result = num1 + num2;
            else if (isMinus)
                result = num1 - num2;
            else if (isMult)
                result = num1 * num2;
            else
                result = num1 / num2;

            st.push(result);
        }

        if (st.size() != 1)
            return 0;

        return st.top();
    }
};

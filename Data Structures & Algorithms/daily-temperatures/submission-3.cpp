class Solution {
public:
    vector<int> dailyTemperatures(const vector<int>& temperatures) {
        const int n = static_cast<int>(temperatures.size());
        std::vector<int> result(n, 0);
        std::vector<int> st;
        st.reserve(temperatures.size());

        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && temperatures[i] > temperatures[st.back()])
            {
                const int j = st.back();
                st.pop_back();
                result[j] = i - j;
            }

            st.push_back(i);
        }

        return result;
    }
};
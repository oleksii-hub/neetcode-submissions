class Solution {
public:
    vector<int> dailyTemperatures(const vector<int>& temperatures) {
        std::vector<std::pair<int, int>> st;
        const int N = temperatures.size();
        std::vector<int> result(N, 0);

        for (std::size_t i = N; i-- > 0;)
        {
            while (!st.empty())
            {
                if (temperatures[i] < st.back().first)
                    break;

                st.pop_back();
            }

            if (st.empty())
            {
                st.push_back({temperatures[i], i});
                continue;
            }

            result[i] = st.back().second - i;
            st.push_back({temperatures[i], i});
        }

        return result;
    }
};

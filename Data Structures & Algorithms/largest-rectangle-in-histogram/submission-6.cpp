class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::vector<int> st;
        st.reserve(heights.size());
        const int n = static_cast<int>(heights.size());
        int biggestArea = 0;

        for (std::size_t i = 0; i <= n; ++i)
        {
            int h = (i == n) ? 0 : heights[i];
            while(!st.empty() && heights[st.back()] >= h)
            {
                const int height = heights[st.back()];
                st.pop_back();
                const int left = st.empty() ? -1 : st.back();
                const int width = i - left - 1;
                biggestArea = std::max(biggestArea, width * height);
            }

            st.push_back(i);
        }

        return biggestArea;
    }
};

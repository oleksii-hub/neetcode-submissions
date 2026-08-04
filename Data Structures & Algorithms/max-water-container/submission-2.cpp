class Solution {
public:
    int maxArea(vector<int>& heights) {
        std::ptrdiff_t left = 0;
        std::ptrdiff_t right = heights.size() - 1;

        int maxAreaRes = 0;
        while(left < right)
        {
            const int width = static_cast<int>(right - left);
            maxAreaRes = std::max(maxAreaRes, width * std::min(heights[left], heights[right]));
            if (heights[left] < heights[right])
                ++left;
            else
                --right;
        }

        return maxAreaRes;
    }
};

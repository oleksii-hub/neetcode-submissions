class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;

        int biggestArea = 0;
        for (std::size_t i = 0; i < heights.size(); ++i)
        {
            int currHeight = heights[i];
            biggestArea = std::max(biggestArea, currHeight);
            std::size_t j = i + 1;
            while(j != heights.size())
            {
                currHeight = std::min(currHeight, heights[j]);
                int width = static_cast<int>(j - i + 1);
                int area = width * currHeight;
                biggestArea = std::max(biggestArea, area);
                ++j;
            }
        }

        return biggestArea;
    }
};

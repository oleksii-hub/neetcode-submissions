class Solution {
public:
    int trap(vector<int>& height) {
        std::ptrdiff_t left = 0;
        std::ptrdiff_t right = left + 1;
        const auto n = std::ssize(height);

        std::ptrdiff_t totalArea = 0;
        while (right < n) {
            if(height[left] <= height[right])
            {
                ++left;
                ++right;
                continue;
            }

            int maxRight = height[right];
            auto maxRightIdx = right;
            bool hole = false;
            while(right < n && height[left] > height[right])
            {
                if (height[right] > maxRight)
                {
                    maxRight = height[right];
                    maxRightIdx = right;
                }

                // if (right != left + 1 && height[right] > height[right - 1])
                //     hole = true;

                ++right;
            }

            if (right == n)
            {
                // if (!hole)
                //     break;

                right = maxRightIdx;
            }

            const auto h = std::min(height[left], height[right]);
            for (auto i = left + 1; i < right; ++i)
                totalArea += h - height[i];

            left = right;
            right = left + 1;
        }

        return static_cast<int>(totalArea);
    }
};

class Solution {
public:
    std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
        const auto n = std::ssize(nums);
        const std::ptrdiff_t width = k;

        std::deque<std::ptrdiff_t> maxQ;
        std::vector<int> res;
        res.reserve(static_cast<std::size_t>(n - width + 1));

        for (std::ptrdiff_t r = 0; r < n; ++r) {
            while (!maxQ.empty() && nums[maxQ.back()] <= nums[r]) {
                maxQ.pop_back();
            }
            maxQ.push_back(r);

            if (maxQ.front() < r - width + 1) {
                maxQ.pop_front();
            }

            if (r >= width - 1) {
                res.push_back(nums[maxQ.front()]);
            }
        }

        return res;
    }
};
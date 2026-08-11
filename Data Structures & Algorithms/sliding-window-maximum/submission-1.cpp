class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 6, 4, 2, 3, 5, 0, 1, ...
        // 0, 1, 2, 3, 4, 5, 6, ...
        const auto n = std::ssize(nums);
        std::deque<std::ptrdiff_t> st;
        std::vector<int> res;
        res.reserve(n - k + 1);
        for (std::ptrdiff_t r = 0; r < n; ++r)
        {
            while (!st.empty() && nums[r] > nums[st.back()])
            {
                st.pop_back();
            }

            st.push_back(r);

            if (r >= k - 1)
            {
                res.push_back(nums[st.front()]);
            }

            if (st.front() <= r - k + 1)
                st.pop_front();
        }
        
        return res;
    }
};

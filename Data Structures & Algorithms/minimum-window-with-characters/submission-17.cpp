class Solution {
public:
    string minWindow(string s, string t) {
        constexpr auto idx = [] (char ch) noexcept -> std::size_t
        {
            if (ch >= 'a')
                return static_cast<std::size_t>(ch - 'a');
            else
                return static_cast<std::size_t>(ch - 'A' + 26);
        };

        std::array<int, 52> have{};
        std::array<int, 52> need{};
        int required = 0;
        for(auto ch : t)
        {
            if (need[idx(ch)]++ == 0) { ++required; }
        }

        int matched = 0;
        std::ptrdiff_t l = 0;
        std::ptrdiff_t bestL = 0;
        std::ptrdiff_t bestSize = 0;
        const auto n = std::ssize(s);
        for (std::ptrdiff_t r = 0; r < n; ++r)
        {
            const auto in = idx(s[r]);
            ++have[in];
            if (have[in] == need[in]) { ++matched; }

            // Min Window Substring — sliding window, shortest — used the longest skeleton;
            // record point and shrink condition both  wrong.
            // Fix: shrink while valid, measure before each removal.
            while (matched == required)
            {
                const auto size = r - l + 1;
                if (bestSize == 0 || size < bestSize)
                {
                    bestSize = size;
                    bestL = l;
                }

                auto out = idx(s[l]);
                if (have[out] == need[out]) { --matched; }
                --have[out];
                ++l;
            }
        }

        return s.substr(
            static_cast<std::size_t>(bestL),
            static_cast<std::size_t>(bestSize));
    }
};
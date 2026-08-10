#include <ranges>

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

        const auto k = std::ssize(t);
        const auto n = std::ssize(s);
        if (k > n) {
            return "";
        }

        std::array<int, 52> have{};
        std::array<int, 52> need{};
        for(auto ch : t)
        {
            ++need[idx(ch)];
        }

        int matched = 0;
        for (std::size_t c = 0; c < 52; ++c) {
            matched += (need[c] == 0) ? 1 : 0;
        }

        std::ptrdiff_t l = 0;
        std::ptrdiff_t bestL = 0;
        std::ptrdiff_t bestSize = 0;
        for (std::ptrdiff_t r = 0; r < n; ++r)
        {
            auto in = idx(s[r]);
            bool matchedBefore = have[in] >= need[in];
            ++have[in];
            if (!matchedBefore && have[in] >= need[in]) { ++matched; }

            // while(r > l && need[idx(s[l])] == 0)
            // {
            //     ++l;
            // }

            while (matched == 52)
            {
                const auto size = r - l + 1;
                if (bestSize == 0 || size < bestSize)
                {
                    bestSize = size;
                    bestL = l;
                }

                auto out = idx(s[l]);
                bool matchedBefore = have[out] >= need[out];
                --have[out];
                ++l;
                if (matchedBefore && have[out] < need[out]) { --matched; }
            }
        }

        return s.substr(bestL, bestSize);
    }
};
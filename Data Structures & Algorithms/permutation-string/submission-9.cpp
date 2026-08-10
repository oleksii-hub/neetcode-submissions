class Solution {
public:
    bool checkInclusion(std::string_view s1, std::string_view s2) {
        constexpr auto idx = [](char ch) noexcept -> std::size_t {
            return static_cast<std::size_t>(ch - 'a');
        };

        const auto k = std::ssize(s1);
        if (k > std::ssize(s2)) {
            return false;
        }

        std::array<int, 26> need{};
        std::array<int, 26> have{};
        for (const char ch : s1) {
            ++need[idx(ch)];
        }

        int matched = 0;
        for (std::size_t c = 0; c < 26; ++c) {
            matched += (need[c] == 0) ? 1 : 0;
        }

        for (std::ptrdiff_t r = 0; r < std::ssize(s2); ++r) {
            const auto in = idx(s2[r]);
            if (have[in] == need[in]) { --matched; }

            ++have[in];

            if (have[in] == need[in]) { ++matched; }

            if (r >= k) {
                const auto out = idx(s2[r - k]);
                if (have[out] == need[out]) { --matched; }

                --have[out];

                if (have[out] == need[out]) { ++matched; }
            }

            if (matched == 26) {
                return true;
            }
        }

        return false;
    }
};
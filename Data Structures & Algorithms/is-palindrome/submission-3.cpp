class Solution {
public:
    [[nodiscard]] bool isPalindrome(std::string_view s) const noexcept {
        constexpr auto isAlnum = [](char ch) noexcept {
            return (ch >= '0' && ch <= '9') ||
                   (ch >= 'a' && ch <= 'z') ||
                   (ch >= 'A' && ch <= 'Z');
        };

        constexpr auto toLowerAscii = [](char ch) noexcept -> char {
            return (ch >= 'A' && ch <= 'Z') ? static_cast<char>(ch - 'A' + 'a') : ch;
        };

        std::size_t left = 0;
        std::size_t right = s.size();

        while (left < right) {
            const char lc = s[left];
            if (!isAlnum(lc)) {
                ++left;
                continue;
            }

            const char rc = s[right - 1];
            if (!isAlnum(rc)) {
                --right;
                continue;
            }

            if (toLowerAscii(lc) != toLowerAscii(rc)) {
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }
};
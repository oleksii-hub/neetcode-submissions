class Solution {
public:
    bool isPalindrome(string s) {
        auto isAlphanumeric = [](char ch)
        {
            if (ch >= 'A' && ch <= 'Z')
                return true;
            
            if (ch >= 'a' && ch <= 'z')
                return true;

            if (ch >= '0' && ch <= '9')
                return true;

            return false;
        };

        int left = 0;
        int right = s.size() - 1;
        while (left <= right)
        {
            if (!isAlphanumeric(s[left]))
            {
                ++left;
                continue;
            }

            if (!isAlphanumeric(s[right]))
            {
                --right;
                continue;
            }

            char lowerLeft = static_cast<char>(std::tolower(s[left]));
            char lowerRight = static_cast<char>(std::tolower(s[right]));
            if (lowerLeft != lowerRight)
                return false;

            ++left;
            --right;
        }

        return true;
    }
};

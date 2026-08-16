class Solution {
public:
    double findMedianSortedArrays(const std::vector<int>& nums1,
                                  const std::vector<int>& nums2) {
        const auto& A = (nums1.size() <= nums2.size()) ? nums1 : nums2;
        const auto& B = (nums1.size() <= nums2.size()) ? nums2 : nums1;

        const auto m = std::ssize(A);
        const auto n = std::ssize(B);
        const auto half = (m + n + 1) / 2;

        constexpr int NEG_INF = std::numeric_limits<int>::min();
        constexpr int POS_INF = std::numeric_limits<int>::max();

        std::ptrdiff_t lo = 0;
        std::ptrdiff_t hi = m;

        while (lo <= hi) {
            const auto i = lo + (hi - lo) / 2;
            const auto j = half - i;

            const int aLeft  = (i > 0) ? A[i - 1] : NEG_INF;
            const int aRight = (i < m) ? A[i]     : POS_INF;
            const int bLeft  = (j > 0) ? B[j - 1] : NEG_INF;
            const int bRight = (j < n) ? B[j]     : POS_INF;

            if (aLeft <= bRight && bLeft <= aRight) {
                const int maxLeft = std::max(aLeft, bLeft);

                if ((m + n) % 2 == 1) {
                    return maxLeft;
                }

                const int minRight = std::min(aRight, bRight);
                return (maxLeft + minRight) / 2.0;
            }

            if (aLeft > bRight) {
                hi = i - 1;      // took too many from A
            } else {
                lo = i + 1;      // took too few from A
            }
        }

        return 0.0;   // unreachable given valid input
    }
};
class Solution {
public:
    int search(const std::vector<int>& nums, int target) {
        const auto n = std::ssize(nums);

        // 1. find pivot (index of minimum) — the previous problem, verbatim
        std::ptrdiff_t lo = 0, hi = n - 1;
        while (lo < hi) {
            const auto mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[hi]) { hi = mid; }
            else { lo = mid + 1; }
        }
        const auto pivot = lo;

        // 2. standard boundary search over the rotated index space
        lo = 0;
        hi = n;
        while (lo < hi) {
            const auto mid = lo + (hi - lo) / 2;
            const auto real = (mid + pivot) % n;
            if (nums[real] >= target) { hi = mid; }
            else { lo = mid + 1; }
        }

        const auto real = (lo + pivot) % n;
        return (lo < n && nums[real] == target) ? static_cast<int>(real) : -1;
    }
};
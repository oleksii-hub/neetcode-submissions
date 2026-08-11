class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        std::ranges::sort(piles);
        constexpr auto ceilDiv = [](int a, int b) -> int
        {
            return (a + b - 1) / b;
        };

        std::ptrdiff_t lo = 1;
        std::ptrdiff_t hi = piles.back() + 1;
        const auto n = std::ssize(piles);
        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2; // speed
            int hours = 0;
            for (const int pile : piles) {
                hours += ceilDiv(pile, mid);
            }

            if (hours <= h) { hi = mid; }
            else { lo = mid + 1; }
        }

        return lo;
    }
};

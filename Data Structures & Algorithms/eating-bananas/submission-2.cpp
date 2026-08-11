class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        constexpr auto ceilDiv = [](int a, int b) -> int
        {
            return (a + b - 1) / b;
        };

        int lo = 1;
        int hi = *std::ranges::max_element(piles) + 1;
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

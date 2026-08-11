class Solution {
public:
    int minEatingSpeed(const std::vector<int>& piles, int h) {
        constexpr auto ceilDiv = [](int a, int b) noexcept -> long long {
            return (static_cast<long long>(a) + b - 1) / b;
        };

        const auto feasible = [&](int speed) noexcept {
            long long hours = 0;
            for (const int pile : piles) {
                hours += ceilDiv(pile, speed);
                if (hours > h) { return false; }
            }
            return true;
        };

        int lo = 1;
        int hi = *std::ranges::max_element(piles);

        while (lo < hi) {
            const int mid = lo + (hi - lo) / 2;
            if (feasible(mid)) { hi = mid; }
            else { lo = mid + 1; }
        }

        return lo;
    }
};
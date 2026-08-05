class Solution {
public:
    int maxProfit(const std::vector<int>& prices) {
        int minPrice = std::numeric_limits<int>::max();
        int best = 0;

        for (const int price : prices) {
            best = std::max(best, price - minPrice);
            minPrice = std::min(minPrice, price);
        }

        return best;
    }
};
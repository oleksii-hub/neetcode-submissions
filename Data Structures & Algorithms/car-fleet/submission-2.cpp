#include <numeric>

class Solution {
public:
    int carFleet(int target, const vector<int>& positions, const vector<int>& speeds) {
        std::vector<std::pair<int, int>> cars;
        cars.reserve(positions.size());
        for (std::size_t i = 0; i < positions.size(); i++)
        {
            cars.emplace_back(positions[i], speeds[i]);
        }

        std::ranges::sort(cars, std::ranges::greater{});

        int fleets = 0;
        int leadDist = 0, leadSpeed = 1;
        for (const auto [pos, speed] : cars)
        {
            int dist = target - pos;
            if (dist * leadSpeed > leadDist * speed)
            {
                ++fleets;
                leadDist = dist;
                leadSpeed = speed;
            }
        }

        return fleets;
    }
};

class TimeMap {
    struct ValueNode
    {
        std::string value;
        int timestamp;
    };

    std::unordered_map<std::string, std::vector<ValueNode>> nodes;
public:
    TimeMap() = default;
    
    void set(string key, string value, int timestamp) {
        nodes[key].emplace_back(ValueNode{value, timestamp});
    }
    
    string get(string key, int timestamp) {
        const auto it = nodes.find(key);
        if (it == nodes.end())
            return {};

        const auto& sortedValues = it->second;
        const auto n = std::ssize(sortedValues);
        std::ptrdiff_t lo = 0;
        std::ptrdiff_t hi = n;
        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;
            if (sortedValues[mid].timestamp >= timestamp)
                hi = mid;
            else
                lo = mid + 1;
        }

        if (lo < n && sortedValues[lo].timestamp == timestamp)
            return sortedValues[lo].value;

        if (lo - 1 >= 0 && sortedValues[lo - 1].timestamp <= timestamp)
            return sortedValues[lo - 1].value;

        return {};
    }
};

class TimeMap {
    struct ValueNode {
        std::string value;
        int timestamp;
    };

    std::unordered_map<std::string, std::vector<ValueNode>> nodes;

public:
    void set(std::string key, std::string value, int timestamp) {
        nodes[std::move(key)].emplace_back(std::move(value), timestamp);
    }

    std::string get(const std::string& key, int timestamp) const {
        const auto it = nodes.find(key);
        if (it == nodes.end()) {
            return {};
        }

        const auto& values = it->second;

        std::ptrdiff_t lo = 0;
        std::ptrdiff_t hi = std::ssize(values);

        while (lo < hi) {
            const auto mid = lo + (hi - lo) / 2;
            if (values[mid].timestamp > timestamp) { hi = mid; }
            else { lo = mid + 1; }
        }

        return lo > 0 ? values[lo - 1].value : std::string{};
    }
};
class LRUCache {
    using Entry = std::pair<int, int>;              // key, value
    using EntryIt = std::list<Entry>::iterator;

    std::list<Entry> cache_;                        // front = LRU, back = MRU
    std::unordered_map<int, EntryIt> index_;
    std::size_t capacity_;

public:
    explicit LRUCache(int capacity)
        : capacity_(static_cast<std::size_t>(capacity)) {
        index_.reserve(capacity_);
    }

    int get(int key) {
        const auto it = index_.find(key);
        if (it == index_.end()) {
            return -1;
        }

        cache_.splice(cache_.end(), cache_, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        if (const auto it = index_.find(key); it != index_.end()) {
            it->second->second = value;
            cache_.splice(cache_.end(), cache_, it->second);
            return;
        }

        if (cache_.size() == capacity_) {
            index_.erase(cache_.front().first);
            cache_.pop_front();
        }

        cache_.emplace_back(key, value);
        index_.emplace(key, std::prev(cache_.end()));
    }
};
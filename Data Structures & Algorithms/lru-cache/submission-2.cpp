class LRUCache {
public:
    using listIt = std::list<int>::iterator;

    std::unordered_map<int, std::pair<int, listIt>> keyValue_;
    std::list<int> cache_;
    int capacity_;

    LRUCache(int capacity)
    {
        capacity_ = capacity;
    }
    
    int get(int key) {
        const auto it = keyValue_.find(key);
        if (it == keyValue_.end())
        {
            return -1;
        }

        int value = it->second.first;
        cache_.splice(cache_.end(), cache_, it->second.second);
        return value;
    }
    
    void put(int key, int value) {
        if (auto it = keyValue_.find(key); it != keyValue_.end())
        {
            cache_.erase(it->second.second);
        }

        cache_.push_back(key);
        keyValue_[key] = std::make_pair(value, std::prev(cache_.end()));

        if (cache_.size() > capacity_)
        {
            keyValue_.erase(*cache_.begin());
            cache_.erase(cache_.begin());
        }
    }
};
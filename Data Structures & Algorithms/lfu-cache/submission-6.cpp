class LFUCache {
    struct Node {
        int value, freq, timestamp;

        Node(int v, int f, int t) : value(v), freq(f), timestamp(t) {}
    };

    unordered_map<int,Node*> cache;
    int capacity, timestamp;
public:
    LFUCache(int capacity): capacity(capacity), timestamp(0) {}
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        cache[key]->freq++;
        cache[key]->timestamp = ++timestamp;
        return cache[key]->value;
    }
    
    void put(int key, int value) {
        timestamp++;
        if (cache.find(key) != cache.end()) {
            cache[key]->value = value;
            cache[key]->freq++;
            cache[key]->timestamp = timestamp;
            return;
        }

        if (cache.size() >= capacity) {
            int minFreq = INT_MAX, minTimestamp = INT_MAX, lfuKey = -1;

            for (const auto& [k, node] : cache) {
                if (node->freq < minFreq || (node->freq == minFreq && node->timestamp < minTimestamp)) {
                    minFreq = node->freq;
                    minTimestamp = node->timestamp;
                    lfuKey = k;
                }
            }
            delete cache[lfuKey];
            cache.erase(lfuKey);
        }

        cache[key] = new Node(value, 1, timestamp);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
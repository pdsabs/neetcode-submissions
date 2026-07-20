class LRUCache {
    struct Node {
        int key, val;
        Node* prev;
        Node* next;

        Node (int key, int val): key{key}, val{val}, prev{nullptr}, next{nullptr} {}
    };

    Node* dummyHead;
    Node* dummyTail;

    unordered_map<int, Node*> cache;

    int size;
    int capacity;
public:
    LRUCache(int capacity) : capacity{capacity}, size{0} {
        dummyHead = new Node(-1, -1);
        dummyTail = new Node(-1, -1);
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    
    void insert(Node* insertMe) {
        dummyHead->next->prev = insertMe;
        insertMe->next = dummyHead->next;
        insertMe->prev = dummyHead;
        dummyHead->next = insertMe;
        cache[insertMe->key] = insertMe;
        size++;
    }

    void remove(Node* removeMe) {
        removeMe->prev->next = removeMe->next;
        removeMe->next->prev = removeMe->prev;
        cache.erase(removeMe->key);
        size--;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        } 
        Node* used = cache[key];
        remove(used);
        insert(used);
        return used->val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }

        Node* newNode = new Node(key, value);
        insert(newNode);

        if (size > capacity) {
            Node* lru = dummyTail->prev;
            remove(dummyTail->prev);
            delete lru;
        }
    }
};

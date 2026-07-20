class LinkedList {
    struct Node {
        int val;
        Node* next;
        
        Node(int v): val(v), next(nullptr){}
        Node(int v, Node* nextNode): val(v), next(nextNode){}
    };

    Node* head; //dummy
    Node* tail;
    int size;
public:
    LinkedList() {
        head = new Node(0);
        tail = head;
        size = 0;
    }

    int get(int index) {
        if (index >= size) {
            return -1;
        }

        Node* curr = head->next;
        while (index--) {
            curr = curr->next;
        }

        return curr->val;
    }

    void insertHead(int val) {
        Node* newHead = new Node(val, head->next);
        head->next = newHead;
        if (tail == head) tail = newHead;
        size++;
    }
    
    void insertTail(int val) {
        Node* newTail = new Node(val);
        tail->next = newTail;
        tail = newTail;
        size++;
    }

    bool remove(int index) {
        if (index >= size) {
            return false;
        }

        Node* prev = head;
        Node* curr = head->next;

        while (index--) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        if (tail == curr) tail = prev;
        delete curr;
        size--;
        return true;
    }

    vector<int> getValues() {
        vector<int> vals;
        Node* currNode = head->next;
        int sizeCnt = size;
        while (size--) {
            vals.push_back(currNode->val);
            currNode = currNode->next;
        }
        return vals;
    }
};

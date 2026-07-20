class Deque {
    struct Node {
        int val;
        Node* prev;
        Node* next;

        Node(int v) : val(v), prev(nullptr), next(nullptr) {}
        Node(int val, Node* prev, Node* next) :  val(val), prev(prev), next(next) {}
    };

    Node* head;
    Node* tail;
    int size;
public:
    Deque() {
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    void append(int value) {
       Node* newNode = new Node(value, tail->prev, tail);
       tail->prev->next = newNode;
       tail->prev = newNode;
       size++; 
    }

    void appendleft(int value) {
        Node* newNode = new Node(value, head, head->next);
        head->next->prev = newNode;
        head->next = newNode;
        size++;
    }

    int pop() {
        Node* target = tail->prev;
        if (!target || target == head) {
            return -1;
        } else {
            target->prev->next = target->next;
            target->next->prev = target->prev;
        }
        int value = target->val;
        delete target;
        size--;
        return value;
    }

    int popleft() {
        Node* target = head->next;
        if (!target || target == tail) {
            return -1;
        } else {
            target->prev->next = target->next;
            target->next->prev = target->prev;
        }
        int value = target->val;
        delete target;
        size--;
        return value;
    }
};

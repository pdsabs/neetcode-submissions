class PrefixTree {
    struct Node {
        char val;
        bool is_word;
        array<Node*, 26> children{};
        Node(char val): val{val}, is_word(false) {}
        ~Node() {
            for (Node* child : children) {
                delete child;
            }
        }
    };

    Node* root;

public:
    PrefixTree() {
        root = new Node('R');
    }

    ~PrefixTree() {
        delete root;
    }
    
    void insert(string word) {
        Node* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';

            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new Node(ch);
            }

            curr = curr->children[idx];
        }

        curr->is_word = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';

            if (curr->children[idx] == nullptr) {
                return false;
            }

            curr = curr->children[idx];
        }

        return curr->is_word;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (char ch : prefix) {
            int idx = ch - 'a';

            if (curr->children[idx] == nullptr) {
                return false;
            }

            curr = curr->children[idx];
        }

        return true;
    }
};

class MinStack {
    unordered_map<int,int> freq;
    priority_queue<int, vector<int>, greater<int>> pq;
    stack<int> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        st.push(val);
        pq.push(val);
    }
    
    void pop() {
        freq[st.top()]--;
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        while (freq[pq.top()] == 0) pq.pop();
        return pq.top();
    }
};

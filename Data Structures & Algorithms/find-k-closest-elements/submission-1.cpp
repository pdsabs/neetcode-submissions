class Solution {
    struct Compare {
        int x;

        Compare(int target) : x(target) {}

        bool operator()(const int& a, const int& b) {
            int absA = abs(a-x);
            int absB = abs(b-x);
            if (absA == absB) {
                return a > b;
            } else {
                return absA > absB;
            }
        }
    };
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<int, vector<int>, Compare> pq{Compare(x)};
        for (int val : arr) {
            pq.push(val);
        }

        vector<int> res;
        while (k--) {
            res.push_back(pq.top());
            pq.pop();
        }

        sort(res.begin(), res.end());
        return res;
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) return false;

        vector<vector<int>> adj (n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        set<int> seen;
        queue<pair<int,int>> q; // node, parent
        q.push({0, -1});
        seen.insert(0);

        while (!q.empty()) {
            pair<int,int> curr = q.front();
            q.pop();

            int curr_node = curr.first;
            int parent = curr.second;

            for (int& connect : adj[curr_node]) {
                if (connect == parent) continue;

                if (seen.count(connect) == 1) return false;
                
                seen.insert(connect);
                q.push({connect, curr_node});
            }

        }

        return seen.size() == n;
    }
};

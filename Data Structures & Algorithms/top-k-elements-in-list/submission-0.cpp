class Solution {
    

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freqmap; // num to freq
        priority_queue<pair<int,int>> pq; //max heap by default, will compare first value of pair first as well

        for (int n : nums) {
            freqmap[n]++;
        }

        for (auto& pair : freqmap) {
            pq.push({pair.second, pair.first});
        }

        vector<int> res;
        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};

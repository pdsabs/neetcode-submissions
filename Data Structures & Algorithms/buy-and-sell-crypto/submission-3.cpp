class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprof = 0;
        int currMin = std::numeric_limits<int>::max();

        for (int p : prices) {
            maxprof = max(maxprof, p - currMin);
            currMin = min(p, currMin);
        }

        return maxprof;
    }
};

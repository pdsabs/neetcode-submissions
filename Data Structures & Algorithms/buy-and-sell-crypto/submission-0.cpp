class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = l, maxProf = 0;
        while (r < prices.size()) {
            if (prices[r] < prices[l]) {
                l = r;
            } else {
                maxProf = max(maxProf, prices[r]-prices[l]);
            }
            r++;
        }

        return maxProf;
    }
};

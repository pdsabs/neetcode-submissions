class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;

        int maxProf = 0;
        int i = 0, j = i+1;
        while (j < prices.size()) {
            if (prices[j] < prices[i]) {
                i=j;
            }

            maxProf = max(maxProf, prices[j] - prices[i]);

            j++;
        }

        return maxProf;
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bCnt (n+1, 0);

        for (uint16_t i = 0; i <= n; i++) {
            uint16_t num = i;
            while (num != 0) {
                num &= num-1;
                bCnt[i]++;
            }
        }

        return bCnt;
    }
};

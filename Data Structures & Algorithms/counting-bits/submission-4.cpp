class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bCnt;

        for (uint16_t i = 0; i <= n; i++) {
            uint16_t num = i;
            int cnt = 0;
            while (num != 0) {
                if (num & 1) cnt++;
                num = num >> 1;
            }
            bCnt.push_back(cnt);
        }

        return bCnt;
    }
};

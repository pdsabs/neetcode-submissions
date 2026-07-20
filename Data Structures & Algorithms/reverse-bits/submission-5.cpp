class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        uint32_t num = n;
        for (int i = 0; i < 32; i++) {
            if (num & 1) res = res | (1<<31-i);
            num >>= 1;
        }
        return res;
    }
};

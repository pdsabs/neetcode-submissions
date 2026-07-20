class Solution {
public:

    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        // at each i from 0 to n, you have two options.
        int curr[2] {1, 2};
        int val = 1;
        for (int i = 2; i < n; i++) {
            val = curr[0] + curr[1];
            curr[0] = curr[1];
            curr[1] = val;
        }

        return val;
    }
};

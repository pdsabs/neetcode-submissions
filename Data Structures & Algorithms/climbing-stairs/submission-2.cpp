class Solution {
public:

    int climbStairs(int n) {
        // if (n == 1) return 1;
        // if (n == 2) return 2;
        // at each i from 0 to n, you have two options.
        int z = 1, o = 1;
        for (int i = 0; i < n-1; i++) {
            int temp = o;
            o = o + z;
            z = temp;
        }

        return o;
    }
};

class Solution {
public:
    int helper(int currM, int currN, int m, int n, vector<vector<int>>& memo) {
        if (currM >= m || currN >= n) return 0;
        if (currM == m - 1 || currN == n - 1) return 1;
        if (memo[currM][currN] != 0) return memo[currM][currN];
        memo[currM][currN] = helper(currM + 1, currN, m, n, memo) + helper(currM, currN + 1, m, n, memo);
        return memo[currM][currN];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, 0));
        return helper(0, 0, m, n, memo);
    }
};

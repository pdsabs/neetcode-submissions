class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> charSet(s.begin(), s.end());

        int maxLen = 0;
        for (char c : charSet) {
            int count = 0, l = 0;
            for (int r = 0; r < s.length(); r++) {
                if ( s[r] == c) {
                    count++;
                }

                while ((r - l + 1) - count > k) {
                    if (s[l] == c) {
                        count--;
                    }
                    l++;
                }
                maxLen = max(maxLen, r-l+1);
            }
        }

        return maxLen;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        unordered_map<char, int> seen;
        
        int len = 0;
        int i = 0, j = 0;
        while (j < s.size()) {
            seen[s[j]]++;
            while (seen[s[j]] > 1 && i < j) {
                seen[s[i]]--;
                i++;
            }
            j++;
            len = max(len, (j-i));
        }

        return len;
    }
};

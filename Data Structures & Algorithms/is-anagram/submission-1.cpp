class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sChars;
        unordered_map<char, int> tChars;
        for (int i = 0; i <= s.length(); i++) {
            sChars[s[i]]++;
            tChars[t[i]]++;
        }

        for (const auto& [k,v] : sChars) {
            if (tChars[k] != v) {
                return false;
            }
        }
        return true;
    }
};

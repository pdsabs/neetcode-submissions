class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_set<char> s1set;
        unordered_map<char, int> s1map;
        for (char c: s1) {
            s1set.insert(c);
            s1map[c]++;
        }

        for (int r = 0; r < s2.length(); r++) {
            if (s1set.count(s2[r])) {
                unordered_map<char, int> s2map;
                for (char c: s2.substr(r, s1.size())) {
                    s2map[c]++;
                }
                if (s2map == s1map) return true;
            }
        } 

        return false;
    }
};

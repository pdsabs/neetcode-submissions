class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magMap;
        // magMap = {{'a':0}, {'b':1}}
        for (char c : magazine) {
            magMap[c]++;
        }

        for (char c : ransomNote) {
            if (magMap.find(c) != magMap.end()) {
                if (magMap[c] > 0) {
                    magMap[c]--;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        return true;
    }
};
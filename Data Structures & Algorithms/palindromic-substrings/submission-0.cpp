class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            countPals(s, i, i, res); //odd len
            countPals(s, i, i+1, res); //even len
        }

        return res;
    }

    void countPals(string s, int l, int r, int& res) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            if (s[l] == s[r]) {
                res++;
                l--;
                r++;
            } else {
                break;
            }
        }
    }
};

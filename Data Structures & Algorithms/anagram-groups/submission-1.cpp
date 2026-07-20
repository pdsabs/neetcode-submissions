class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> sublists;

        unordered_map<string, vector<string>> res;
        for (const auto& s : strs) {
            string sSorted = s;
            sort(sSorted.begin(), sSorted.end());
            res[sSorted].push_back(s);
        }

        vector<vector<string>> result;
        for (const auto& [k,v]: res) {
            result.push_back(v);
        }

        return result;
    }
};

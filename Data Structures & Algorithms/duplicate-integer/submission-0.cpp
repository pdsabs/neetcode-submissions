class Solution {
public:
    unordered_set<int> seen;
    bool hasDuplicate(vector<int>& nums) {
        for (int n : nums) {
            if (seen.contains(n)) {
                return true;
            }
            seen.insert(n);
        }
        return false;
    }
};
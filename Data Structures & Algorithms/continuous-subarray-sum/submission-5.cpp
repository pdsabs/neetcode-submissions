class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;

        unordered_map<int, int> remainMap; // remain->index.
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            int remain = currSum % k;

            if (remain == 0 && i > 0) return true;

            if (remainMap.find(remain) != remainMap.end()) {
                if (i - remainMap[remain] >= 2) return true;
            } else {
                remainMap[remain] = i;
            }
        }

        return false;
    }
};
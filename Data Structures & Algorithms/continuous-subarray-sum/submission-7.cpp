class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainMap;

        // use map of remainder->index to see if we have same remainder
        // if we have duplicate remainders, there exists some subarray between
        // the duplicates in which the the sum  is a multiple of k
        int curSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];

            if (i >= 1 && curSum % k == 0) return true;

            //check if remainder exists
            //add remainder to unordered map
            int remain = curSum % k;
            if (remainMap.find(remain) != remainMap.end()) {
                if (i - remainMap[remain] >= 2) {
                    return true;
                }
            } else {
                remainMap[remain] = i;
            }
        }

        return false;
    }
};
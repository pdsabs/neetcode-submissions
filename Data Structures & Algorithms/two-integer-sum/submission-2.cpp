class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> indMap;
        for (int i = 0; i < nums.size(); i++) {
            if (indMap.find(nums[i]) != indMap.end()) return {indMap[nums[i]], i};
            indMap[target-nums[i]] = i;
        }

        return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> targets; //remainder, index
        for (int i = 0; i < nums.size(); i++) {
            if (targets.find(nums[i]) != targets.end()) {
                return {targets[nums[i]], i};
            }
            targets[target - nums[i]] = i;
        }
    }
};

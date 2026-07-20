class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // range: [1,n]
        // size: n+1
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i+1] == nums[i]) return nums[i];
        }

        return -1;
    }
};

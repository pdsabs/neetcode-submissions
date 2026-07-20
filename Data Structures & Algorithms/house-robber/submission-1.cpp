class Solution {
public:


    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int prevprev = nums[0];
        int prev = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            int curr = max(prevprev + nums[i], prev);
            prevprev = prev;
            prev = curr;
        }

        return prev;
    }
};

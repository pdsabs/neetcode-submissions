class Solution {
public:
    int bs(vector<int>& nums, int target, int l, int r) {
        if (l > r) return -1;
        int md = l + (r-l)/2;
        int midVal = nums[md];
        if (midVal > target) {
            return bs(nums, target, l, md-1);
        } else if (midVal < target) {
            return bs(nums, target, md+1, r);
        } else {
            return md;
        }
    }

    int search(vector<int>& nums, int target) {
        return bs(nums, target, 0, nums.size()-1);
    }
};

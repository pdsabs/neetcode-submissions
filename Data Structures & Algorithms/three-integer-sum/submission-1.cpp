class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        for  (int a = 0; a < nums.size(); a++) {
            if (nums[a] > 0) break; //can't sum to zero if leftmost value positive
            if (a > 0 && nums[a-1] == nums[a]) continue;

            int l = a+1, r = nums.size()-1;
            while (l < r) {
                int sum = nums[a] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[a], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l-1]) {
                        l++;
                    }
                } else if (sum > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }

        return res;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int biggest = 0;
        int actual = 0;
        for (int num : nums) {
            actual += num;
        }

        int total = 0;
        for (int i = 0; i <= nums.size(); i++) total += i;

        return total-actual;
    }
};

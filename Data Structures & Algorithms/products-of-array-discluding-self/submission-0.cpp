class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCnt = 0;

        int nonZeroProduct = 1;
        int fullProduct = 1;
        for (int n : nums) {
            fullProduct *= n;
            if (n == 0) {
                zeroCnt++;
            } else {
                nonZeroProduct *= n;
            }
        }

        cout << fullProduct << endl;

        vector<int> output(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (zeroCnt == 1) {
                    output[i] = nonZeroProduct;
                }
            } else {
                cout << nums[i] << endl;
                output[i] = fullProduct / nums[i];
            }
        }

        return output;
    }
};

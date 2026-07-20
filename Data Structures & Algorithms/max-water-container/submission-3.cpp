class Solution {
public:
    int maxArea(vector<int>& heights) {
        int curMax = 0;

        int i = 0, j = heights.size()-1;
        while (i < j) {
            curMax = max(curMax, (min(heights[i], heights[j])*(j-i)));
            if (heights[i] <= heights[j]) {
                i++;
            } else {
                j--;
            }
        }

        return curMax;
    }
};

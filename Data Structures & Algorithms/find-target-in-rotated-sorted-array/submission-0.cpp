class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums[0] < nums.back()) return binarySearch(nums, target, 0, nums.size()-1);

        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        int pivot = l;

        int firstCheck = binarySearch(nums, target, pivot, nums.size()-1);
        if (firstCheck != -1) return firstCheck;
        
        return binarySearch(nums, target, 0, pivot-1);
    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};

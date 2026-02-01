class Solution {
public:
    int searchIndex(vector<int>& nums, int s, int e, int target) {
        if (s > e) {
            return s;
        }

        int mid = s + (e - s) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] > target) {
            return searchIndex(nums, s, mid - 1, target);
        }
        else {
            return searchIndex(nums, mid + 1, e, target);
        }
    }

    int searchInsert(vector<int>& nums, int target) {
        return searchIndex(nums, 0, nums.size() - 1, target);
    }
};

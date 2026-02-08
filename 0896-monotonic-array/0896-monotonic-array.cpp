class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1){
           return true; 
        } 

        int i = 0;
        int j = i + 1;

        // skip equal elements
        while (j < n && nums[i] == nums[j]) {
            i++;
            j++;
        }

        // all elements equal
        if (j == n){
        return true;
        } 

        if (nums[i] <= nums[j]) {
            // increasing
            while (j < n) {
                if (nums[i] > nums[j]) {
                    return false;
                }
                i++;
                j++;
            }
        } else {
            // decreasing
            while (j < n) {
                if (nums[i] < nums[j]) {
                    return false;
                }
                i++;
                j++;
            }
        }
        return true;
    }
};

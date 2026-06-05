class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int n = nums.size();
        if (n == 0){
           return 0;
        } 

        int i = 0;
        int j = 1;

        while (j < n) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
            j++;
        }

        return i + 1;
    }
};
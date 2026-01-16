class Solution {
public:
    int minelementIndex(vector<int>& nums) {
        int mini = INT_MAX;
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < mini) {
                mini = nums[i];
                index = i;
            }
        }
        return index;
    }

    int maxelementIndex(vector<int>& nums) {
        int maxi = INT_MIN;
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                index = i;
            }
        }
        return index;
    }

    int minimumDeletions(vector<int>& nums) {
        int minIndex = minelementIndex(nums);
        int maxIndex = maxelementIndex(nums);
        int n = nums.size();
        if (minIndex > maxIndex){
            swap(minIndex, maxIndex);
        }

        int ans1 = maxIndex + 1;
        int ans2 = n - minIndex;                
        int ans3 = (minIndex + 1) + (n - maxIndex);

        return min({ans1, ans2, ans3});
    }
};

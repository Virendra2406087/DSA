class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>left;
        vector<int>right;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                left.push_back(nums[i]);
            }
            if(nums[i]>pivot){
                right.push_back(nums[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==pivot){
                left.push_back(nums[i]);
            }
        }
        for(int i=0;i<right.size();i++){
            left.push_back(right[i]);
        }
        return left;

    }
};
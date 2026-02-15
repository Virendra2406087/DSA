class Solution {
public:
    void printallPermutation(vector<int>& nums,int i,vector<vector<int>>& ans){
        if(i>=nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            printallPermutation(nums,i+1,ans);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        printallPermutation(nums,0,ans);
        return ans;
    }
};
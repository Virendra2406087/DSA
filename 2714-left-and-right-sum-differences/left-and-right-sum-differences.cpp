class Solution {
public:
    void leftSum(vector<int>& nums,vector<int>& leftsum){
        for(int i=0;i<nums.size()-1;i++){
            leftsum[i+1]=nums[i]+leftsum[i];
        }
    }
    void rightSum(vector<int>& nums,vector<int>& leftsum){
        for(int i=nums.size()-2;i>=0;i--){
            leftsum[i]=nums[i+1]+leftsum[i+1];
        }
    }
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftsum(n,0);
        vector<int>rightsum(n,0);
        leftSum(nums,leftsum);
        rightSum(nums,rightsum);
        vector<int>result;
        for(int i=0;i<n;i++){
            result.push_back(abs(leftsum[i]-rightsum[i]));
        }
        return result;
    }
};
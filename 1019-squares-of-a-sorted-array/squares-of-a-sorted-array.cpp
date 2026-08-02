class Solution {
public:
    void square(vector<int>& nums,vector<int>& ans){
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]*nums[i]);
        }
    }
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans;
        square(nums,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
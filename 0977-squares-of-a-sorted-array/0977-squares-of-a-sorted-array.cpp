class Solution {
public:
    void Square(vector<int>& nums,vector<int>& ans){
        for(int i=0;i<nums.size();i++){
            int sq=nums[i]*nums[i];
            ans.push_back(sq);
        }
        
        
    }
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans;
        Square(nums,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
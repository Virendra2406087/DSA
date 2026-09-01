class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int result=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            unordered_set<int>even;
            unordered_set<int>odd;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0){
                    even.insert(nums[j]);
                } else {
                    odd.insert(nums[j]);
                }
                if(even.size()==odd.size()){
                    result=max(result,j-i+1);
                }
            }
        }
        return result;
    }
};
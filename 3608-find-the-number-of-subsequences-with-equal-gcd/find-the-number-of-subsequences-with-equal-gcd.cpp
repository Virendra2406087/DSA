class Solution {
public:
    int MOD=1e9+7;
    int DP[201][201][201];
    int solve(vector<int>&nums,int i,int first,int second){
        if(i==nums.size()){
            bool bothNonEmpty=(first !=0 && second != 0);
            bool gcdMatch=(first==second);
            return (bothNonEmpty && gcdMatch)? 1:0;
        }
        if(DP[i][first][second] != -1){
            return DP[i][first][second] ;
        }
        int excludes=solve(nums,i+1,first,second);
        int includes1=solve(nums,i+1,__gcd(first,nums[i]),second);
        int includes2=solve(nums,i+1,first,__gcd(second,nums[i]));
        return DP[i][first][second] =(0LL +excludes+includes1+includes2)%MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(DP,-1,sizeof(DP));
        return solve(nums,0,0,0);
    }
};
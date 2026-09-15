class Solution {
public:
    bool isPalidrome(string &s,int i,int j){
        if(i>=j){
            return true;
        }
        if(s[i] != s[j]){
            return false;
        }
        return isPalidrome(s,i+1,j-1);
    }
    int solve(string s,int i,int k){
        if(i >= s.size()){
            return 0;
        }
        int ans=solve(s,i+1,k);
        for(int j=k+i-1;j<s.size();j++){
            if(isPalidrome(s,i,j)){
                ans = max(ans,1 + solve(s,j+1,k));
            }
        }
        return ans;

    }
    int solveUsingMem(string &s,int i,int k,vector<int>& dp){
        if(i >= s.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int ans=solveUsingMem(s,i+1,k,dp);
        for(int j=k+i-1;j<s.size();j++){
            if(isPalidrome(s,i,j)){
                ans = max(ans,1 + solveUsingMem(s,j+1,k,dp));
            }
        }
        dp[i] =ans;
        return dp[i];

    }
    int maxPalindromes(string s, int k) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solveUsingMem(s,0,k,dp);
    }
};
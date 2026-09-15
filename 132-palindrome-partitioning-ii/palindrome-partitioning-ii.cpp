class Solution {
public:
    bool isPalidrome(string & s,int i,int j){
        if(i>=j){
            return true;
        }
        if(s[i] != s[j]){
            return false;
        }
        return isPalidrome(s,i+1,j-1);
    }
    int solve(string &s,int i){
        if(i>=s.size()){
            return 0;
        }
        int count=s.size();
        for(int j=i;j<s.size();j++){
            if(isPalidrome(s,i,j)){
                int ans;
                if(j == s.size()-1){
                    ans = 0;
                } else {
                    ans = 1 + solve(s,j+1);
                }

                count = min(count,ans);
            } 
        }
        return count;
    }
    int solveUsingMem(string &s,int i,vector<int>& dp){
        if(i>=s.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int count=s.size();
        for(int j=i;j<s.size();j++){
            if(isPalidrome(s,i,j)){
                int ans;
                if(j == s.size()-1){
                    ans = 0;
                } else {
                    ans = 1 + solveUsingMem(s,j+1,dp);
                }

                count = min(count,ans);
            } 
        }
        dp[i] = count;
        return dp[i];
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solveUsingMem(s,0,dp);
    }
};
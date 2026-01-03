class Solution {
public:
    int M=1e9+7;
    string states[12]={"RYG","RGY","RYR","RGR","YGR","YRG","YGY","YRY","GRY","GYR","GRG","GYG"};

    int solve(int n,int prev){
        if(n==0){
            return 1;
        }
        int result=0;
        string last=states[prev];
        for(int curr=0;curr<12;curr++){
            if(curr==prev){
                continue;
            }
            string currPat=states[curr];
            bool conflict=false;
            for(int col=0;col<3;col++){
                if(currPat[col]==last[col]){
                    conflict=true;
                    break;
                }
            }
            if(!conflict){
                result=(result+solve(n-1,curr))%M;
            }
        }
        return result;
    }
    int solveMem(int n,int prev,vector<vector<int>>&t){
        if(n==0){
            return 1;
        }
        if(t[n][prev] !=-1){
            return t[n][prev];
        }
        int result=0;
        string last=states[prev];
        for(int curr=0;curr<12;curr++){
            if(curr==prev){
                continue;
            }
            string currPat=states[curr];
            bool conflict=false;
            for(int col=0;col<3;col++){
                if(currPat[col]==last[col]){
                    conflict=true;
                    break;
                }
            }
            if(!conflict){
                result=(result+solveMem(n-1,curr,t))%M;
            }
        }
        t[n][prev]= result;
        return t[n][prev];
    }
    int numOfWays(int n) {
        vector<vector<int>>t;
        t.resize(n,vector<int>(12,-1));
        int result=0;
        for(int i=0;i<12;i++){
            result=(result+solveMem(n-1,i,t))%M;
        }
        return result;
    }
};
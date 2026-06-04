class Solution {
public:
    void covertDigit(int num,vector<int>&ans){
        if(num == 0){
        ans.push_back(0);
        return;
        }
        while(num>0){
            int val=num%10;
            ans.push_back(val);
            num=num/10;
        }
        reverse(ans.begin(),ans.end());
    }
    int waviNess(vector<int>& ans){
        int count=0;
        for(int i=1;i<ans.size()-1;i++){
           if(ans[i]>ans[i-1] && ans[i]>ans[i+1]){
            count++;
           }
           if(ans[i]<ans[i-1] && ans[i]<ans[i+1]){
            count++;
           }
        }
        return count;
    }
    int totalWaviness(int num1, int num2) {
        int totalWaviness=0;
        for(int i=num1;i<=num2;i++){
            vector<int>ans;
            covertDigit(i,ans);
            int wave=waviNess(ans);
            totalWaviness+=wave;
        }
        return totalWaviness;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int mini=INT_MAX;
        for(int i:prices){
            mini=min(mini,i);
            maxProfit=max(maxProfit,i-mini);
        }
        return maxProfit;
    }
}; 
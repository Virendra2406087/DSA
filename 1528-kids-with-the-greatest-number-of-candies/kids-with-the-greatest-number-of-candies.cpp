class Solution {
public:
    int maxvalue(vector<int>& candies){
        int maxi=INT_MIN;
        for(int i=0;i<candies.size();i++){
            maxi=max(maxi,candies[i]);
        }
        return maxi;
    }
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxValue=maxvalue(candies);
        vector<bool>ans;
        int n=candies.size();
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=maxValue){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxi=INT_MIN;
        int i=0,j=0;
        int n =nums.size();
        int totalSum=0;
        while(j < n){
            totalSum+=nums[j];
            if(j-i+1==k){
                maxi=max(maxi,totalSum);
                totalSum -= nums[i];
                i++;
            }
            j++;
            
        }
        double ans = maxi/(double)k;
        return ans;
    }
};
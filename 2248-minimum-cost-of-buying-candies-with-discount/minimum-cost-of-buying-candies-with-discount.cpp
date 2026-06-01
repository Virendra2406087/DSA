class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int totalMinCost=0;
        int n=cost.size();
        int i=0;
        while (i < n) {
            totalMinCost += cost[i];
            if (i + 1 < n){
                totalMinCost += cost[i + 1];
            }
            i += 3;
        }
        return totalMinCost;
    }
};
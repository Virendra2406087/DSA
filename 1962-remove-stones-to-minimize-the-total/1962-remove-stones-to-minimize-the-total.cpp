class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n=piles.size();
        int sum=0;
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
           pq.push(piles[i]);
           sum+=piles[i];
        }
        for(int i=1;i<=k;i++){
            int maxElem=pq.top();
            pq.pop();
            int remove=maxElem/2;
            sum -=remove;
            maxElem -= remove;
            pq.push(maxElem);
        }
        return sum;
    }
};
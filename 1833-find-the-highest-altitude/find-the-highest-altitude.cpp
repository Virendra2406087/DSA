class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>store(n+1);
        store[0]=0;
        for(int i=0;i<n;i++){
            store[i+1]=store[i]+gain[i];
        }
        int maxi=INT_MIN;
        for(int i=0;i<store.size();i++){
            maxi=max(maxi,store[i]);
        }
        return maxi;
    }
};
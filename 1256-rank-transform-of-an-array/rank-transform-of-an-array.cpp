class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int rank=1;
        unordered_map<int,int>rankMap;
        vector<int>temp(arr);
        sort(temp.begin(),temp.end());
        int n=arr.size();
        vector<int>result(n);
        for(int i=0;i<n;i++){
            if(i>0 && temp[i]>temp[i-1]){
                rank++;
            }
            rankMap[temp[i]]=rank;
        }
        for(int i=0;i<n;i++){
            result[i]=rankMap[arr[i]];
        }
        return result;
    }
};
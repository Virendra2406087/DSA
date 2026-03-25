class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string> result(n);
         priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push({score[i],i});
        }
        int count=1;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int index=top.second;
            if(count==1){
                result[index]="Gold Medal";
            }
            else if(count==2){
                result[index]="Silver Medal";
            }
            else if(count==3){
                result[index]="Bronze Medal";
            }else{
                result[index]=to_string(count);
            }
                count++;
        }
        return result;
    }
};
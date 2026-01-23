class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        unordered_map<int,bool>visited;
        q.push(start);
        visited[start]=1;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            if(arr[front]==0){
                return true;
            }else{
                int plus=front+arr[front];
                int minus=front-arr[front];
                if(plus>=0 && plus<arr.size() && visited[plus]==0){
                    q.push(plus);
                    visited[plus]=1;
                }
                if(minus>=0 && minus<arr.size() && visited[minus]==0){
                    q.push(minus);
                    visited[minus]=1;
                }
            }
        }
        return false;
    }
};
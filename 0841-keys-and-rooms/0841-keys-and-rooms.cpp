class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
     int n=rooms.size();
     queue<int>q;
     unordered_map<int,bool>visited;
     int visitedCount=0;
     int src=0;
     q.push(src);
     visited[src]=true;
     visitedCount++;
     while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto nbr:rooms[front]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr]=true;
                visitedCount++;
            }
        }
     }   
     if(visitedCount==n){
        return true;
     }else{
        return false;
     }
    }
};
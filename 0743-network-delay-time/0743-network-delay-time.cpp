class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adjList(n+1);
        for(auto i:times){
            int u=i[0];
            int v=i[1];
            int wt=i[2];
            adjList[u].push_back({v,wt});
        }
        using p=pair<int,int>;
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,k});
        int visitedCount=0;
        unordered_map<int,bool>visited;
        int timeAns=0;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int currTime=top.first;
            int currNode=top.second;
            if(visited[currNode]==true){
                continue;
            }
            visited[currNode]=true;
            visitedCount++;
            timeAns=max(timeAns,currTime);
            for(auto j:adjList[currNode]){
                int nbrNode=j.first;
                if(visited[nbrNode]==false){
                    int edgeKuparKaTime=j.second;
                    pq.push({currTime+edgeKuparKaTime,nbrNode});
                }
            }
        }
        if(visitedCount==n){
            return timeAns;
        }
        return -1;
    }
};
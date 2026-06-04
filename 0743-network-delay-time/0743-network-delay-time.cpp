class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto i:times){
            int u=i[0];
            int v=i[1];
            int wt=i[2];
            adj[u].push_back({v,wt});
        }
        using p=pair<int,int>;
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,k});
        int visitedNodeCount=0;
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
            visitedNodeCount++;
            timeAns=max(timeAns,currTime);
            for(auto j:adj[currNode]){
                int nbrNode=j.first;
                if(visited[nbrNode]==false){
                    int edgeKUparKatime=j.second;
                    pq.push({currTime+edgeKUparKatime,nbrNode});
                }
            }
        }
        if(visitedNodeCount==n){
            return timeAns;
        }else{
            return -1;
        }
    }
};
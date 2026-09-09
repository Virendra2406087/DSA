class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjList(n+1);
        for(auto i:times) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adjList[u].push_back({v,wt});
        }
        using P = pair<int,int>;
        priority_queue<P, vector<P>, greater<P>>pq;
        pq.push({0,k});
        int visitedNodeCount = 0;
        unordered_map<int,bool>visited;
        int timeAns = 0;
        while(! pq.empty()) {
            auto topEle = pq.top();
            pq.pop();
            int currTime = topEle.first;
            int currNode = topEle.second;
            if(visited[currNode]==true) {
                continue;
            }
            visited[currNode]=true;
            visitedNodeCount++;
            timeAns = max(timeAns,currTime);
            for(auto j : adjList[currNode]) {
                int nbrNode = j.first;
                if(visited[nbrNode]==false) {
                    int edgeUpperTime = j.second;
                    pq.push({currTime + edgeUpperTime ,nbrNode});
                }
            }
        }
        if(visitedNodeCount == n) {
            return timeAns;
        } else {
            return -1;
        }

    }
};
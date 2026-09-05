class Solution {
public:
    bool helperDFS(int src, unordered_map<int,vector<int>>& adjList, unordered_map<int,bool>& visited, unordered_map<int,bool>& dfsTracker) {
        visited[src]=true;
        dfsTracker[src]=true;
        for(auto nbr : adjList[src]) {
            if(!visited[nbr]) {
                bool ans = helperDFS(nbr, adjList, visited, dfsTracker);
                if(ans == true) {
                    return true;
                }
            } else  if(visited[nbr] == true && dfsTracker[nbr] == true) {
                return true;
            }
        }
        dfsTracker[src]=false;
        return false;
    }
    
    bool solveUsingDFS(int totalNode, unordered_map<int,vector<int>> &adjList) {
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsTracker;
        for(int src=0; src<totalNode; src++) {
            if(!visited[src]) {
                bool ans = helperDFS(src,adjList, visited,dfsTracker);
                if(ans == true) {
                    return true;
                }
            }
        }
        return false;
    }

    void solveUsingBFS(int n, unordered_map<int,vector<int>>& adjList,vector<int>& topoOrder) {
        unordered_map<int,int> indegree;
        for(auto i : adjList) {
            for(auto nbr : i.second) {
                indegree[nbr]++;
            }
        }
        queue<int>q;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        while(! q.empty()) {
            int front = q.front();
            q.pop();
            topoOrder.push_back(front);
            for(auto nbr : adjList[front]) {
                indegree[nbr]--;
                if(indegree[nbr]==0) {
                    q.push(nbr);
                }
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adjList;
        for(auto i: prerequisites) {
            int u = i[0];
            int v = i[1];
            adjList[v].push_back(u);
        }
        // vector<int> topoOrder;
        // solveUsingBFS(numCourses,adjList,topoOrder);
        // if(topoOrder.size() == numCourses) {
        //     return true;
        // } else {
        //     return false;
        // }
        return !solveUsingDFS(numCourses,adjList);
    }
};
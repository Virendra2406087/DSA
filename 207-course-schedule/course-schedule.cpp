class Solution {
public:
    bool dfsHelper(int src,unordered_map<int,bool> & visited, unordered_map<int,vector<int>> &adjList,unordered_map<int,bool> & dfsTracker) {
        visited[src]=true;
        dfsTracker[src]=true;
        for(auto &nbr : adjList[src]){
            if(!visited[nbr]){
                bool ans = dfsHelper(nbr,visited,adjList,dfsTracker);
                if(ans == true){
                    return true;
            }
            } else if(visited[nbr] == true && dfsTracker[nbr] == true){
                return true;
            }
        }
        dfsTracker[src]=false;
        return false;
    }
    bool solveUsingDFS(int totalNodes,unordered_map<int,vector<int>> &adjList) {
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsTracker;
        for(int src =0; src < totalNodes; src++){
            if(!visited[src]){
                bool ans = dfsHelper(src,visited,adjList,dfsTracker);
                if(ans == true){
                    return true;
                }
            }
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adjList;
        for(auto i : prerequisites) {
            int u = i[0];
            int v = i[1];
            adjList[u].push_back(v);
        }
        return !solveUsingDFS(numCourses,adjList);

    }
};
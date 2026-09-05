class Solution {
public:
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
            adjList[u].push_back(v);
        }
        vector<int> topoOrder;
        solveUsingBFS(numCourses,adjList,topoOrder);
        if(topoOrder.size() == numCourses) {
            return true;
        } else {
            return false;
        }
    }
};
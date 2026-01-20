class Solution {
public:
     void topoOrder(int n,unordered_map<int,list<int>>& adjList,vector<int>&topoSort){
    unordered_map<int,int>indegree;
    queue<int>q;
    for(auto i:adjList){
        for(auto nbr:i.second){
            indegree[nbr]++;
        }
    }
    for(int node=0;node<n;node++){
        if(indegree[node]==0){
            q.push(node);
        }
    }
    while(!q.empty()){
        int front=q.front();
        q.pop();
        topoSort.push_back(front);
        for(auto nbr:adjList[front]){
            indegree[nbr]--;
        if(indegree[nbr]==0){
            q.push(nbr);
           }
        }
    }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adjList;
        for(vector<int>i:prerequisites){
            int u=i[0];
            int v=i[1];
            adjList[v].push_back(u);
        }
        vector<int>topoSort;
        
        topoOrder(numCourses,adjList,topoSort);
        if(topoSort.size()==numCourses){
            return topoSort;
        }else{
           return {};

        }
    }
};
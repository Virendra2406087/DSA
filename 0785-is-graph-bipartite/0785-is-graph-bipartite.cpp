class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,bool>visited;
        unordered_map<int,int>colorOfNode;
        int n=graph.size();
        for(int i=0;i<n;i++){
           colorOfNode[i]=-1;
        }
        queue<int>q;
        int color=0;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
              q.push(i);
              visited[i]=true;
              colorOfNode[i]=color;
              while(!q.empty()){
                int front=q.front();
                q.pop();
                for(auto nbr:graph[front]){
                    if(colorOfNode[front]==colorOfNode[nbr]){
                        return false;
                    }
                    if(visited[nbr]==false){
                        q.push(nbr);
                        visited[nbr]=true;
                        int frontKaColor=colorOfNode[front];
                        colorOfNode[nbr]=!frontKaColor;
                    }
                }
              }
            }
        }
        return true;
    }
};
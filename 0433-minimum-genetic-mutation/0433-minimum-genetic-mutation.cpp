class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>bankset(bank.begin(),bank.end());
        unordered_set<string>visited;
        queue<string>q;
        q.push(startGene);
        visited.insert(startGene);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                if(curr==endGene){
                    return level;
                }
                for(char ch:"ACGT"){
                    for(int i=0;i<curr.size();i++){
                        string neighbour=curr;
                        neighbour[i]=ch;
                        if(visited.find(neighbour)==visited.end() && bankset.find(neighbour) != bankset.end() ){
                            visited.insert(neighbour);
                            q.push(neighbour);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
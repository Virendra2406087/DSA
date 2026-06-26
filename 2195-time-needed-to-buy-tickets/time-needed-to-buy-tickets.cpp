class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;

        for(int i=0;i<tickets.size();i++){
            q.push({i, tickets[i]});
        }

        int time = 0;

        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            cur.second--;
            time++;

            if(cur.second == 0){
                if(cur.first == k)
                    return time;
            }else{
                q.push(cur);
            }
        }

        return time;
    }
};
class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int>ans;
        vector<int>index;
        for(auto j:friends){
            for(int i=0;i<order.size();i++){
                if(j==order[i]){
                    index.push_back(i);
                }
            }
        }
        sort(index.begin(),index.end());
        for(int i=0;i<index.size();i++){
            ans.push_back(order[index[i]]);
        }
        return ans;

    }
};
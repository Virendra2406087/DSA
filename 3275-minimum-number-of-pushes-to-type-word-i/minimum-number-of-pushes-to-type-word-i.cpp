class Solution {
public:
    int minimumPushes(string word) {
        int result=0;
        unordered_map<int,int>mp;
        int assign=2;
        for(char c:word){
            if(assign>9){
                assign=2;
            }
            mp[assign]++;
            result+=mp[assign];
            assign++;
        }
        return result;
    }
};
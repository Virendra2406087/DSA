class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        for(int i=0;i<strs.size();i++){
            string original=strs[i];
            string arrange=original;
            sort(arrange.begin(),arrange.end());
            m[arrange].push_back(original);
        } 
        vector<vector<string>>ans;
        for(auto i:m){
          ans.push_back(i.second);
        }
        return ans;
    }
};
class Solution {
public:
    struct TrieNode{
      unordered_map<int,TrieNode*>children;
      vector<string>words;
    };
    TrieNode* getNode(){
        TrieNode * temp= new TrieNode();
        return temp;
    }
    void insert(TrieNode* root, vector<int>& freq, string &word) {
        TrieNode * temp=root;
        for(int i=0;i<26;i++){
            int count=freq[i];
            if(temp->children.find(count) == temp->children.end()) {
                temp->children[count]=getNode();
            }
            temp=temp->children[count];
        }
        temp->words.push_back(word);
    }
    void solve(TrieNode* root,vector<vector<string>> & ans) {
        if(root->words.size() > 0){
            ans.push_back(root->words);
        }
        for(auto &i:root->children) {
            solve(i.second,ans);
        }
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> ans;
        TrieNode* root=getNode();
        for(int i=0;i<strs.size();i++){
            vector<int>freq(26,0);
            for(char ch:strs[i]) {
                freq[ch-'a']++;
            }
            insert(root,freq,strs[i]);
        }
        solve(root,ans);
        return ans;
    }
};
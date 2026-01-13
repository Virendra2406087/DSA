class TrieNode{
    public:
    char data;
    bool isTerminal;
    unordered_map<char,TrieNode*>children;
    int count;
    TrieNode(char val){
        data=val;
        isTerminal=false;
        count=0;
    }
};


class Solution {
public:
    void insert(TrieNode* root,string str){
         if(str.length()==0){
            root->isTerminal=true;
            return;
         }
         char ch=str[0];
         TrieNode* child;
         if(root->children.find(ch) != root->children.end()){
            child=root->children[ch];
         }else{
            child=new TrieNode(ch);
            root->children[ch]=child;
            root->count++;
         }
         insert(child,str.substr(1));
    }
    string LCP(TrieNode* root,string str){
        string ans="";
        if(root->isTerminal==true){
            return ans;
        }
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(root->count==1){
                ans.push_back(ch);
                root=root->children[ch];
            }else{
                break;
            }
            if(root->isTerminal){
                break;
            }
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root=new TrieNode('_');
        for(int i=0;i<strs.size();i++){
             string str=strs[i];
             insert(root,str);
        }
        string ans=LCP(root,strs[0]);
        return ans;
    }
};
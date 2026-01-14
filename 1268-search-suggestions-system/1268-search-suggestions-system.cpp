class TrieNode{
    public:
    char data;
    unordered_map<char,TrieNode*>children;
    bool isTerminal;
    TrieNode(char val){
        data=val;
        isTerminal=false;
    }
};

class Solution {
public:
    void insert(TrieNode* root,string word){
    if(word.length()==0){   
        root->isTerminal=true;
        return;
    }

    TrieNode* child;
    char ch=word[0];

    if(root->children.find(ch) != root->children.end()){
        child=root->children[ch];
    }else{
        child=new TrieNode(ch);
        root->children[ch]=child;
    }
    insert(child,word.substr(1));

}
void storeSuggestion(TrieNode* root,string &prefix,vector<string>& output){

    if(root->isTerminal){
      output.push_back(prefix);
    }

    for(auto i:root->children){
        char ch=i.first;
        TrieNode* next=i.second;
        if(next !=NULL){
            prefix.push_back(ch);
            storeSuggestion(next,prefix,output);
            prefix.pop_back();
        }
    }
}
vector<string>getSuggestion(TrieNode* root,string &prefix){

    for(char ch : prefix){
            if(root->children.find(ch) == root->children.end()){
                return {};
            }
            root = root->children[ch];
        }
    vector<string>temp;
    storeSuggestion(root,prefix,temp);
    sort(temp.begin(),temp.end());
    if(temp.size()>3){
        temp.resize(3);
    }
    return temp;
}
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    sort(products.begin(),products.end());

    TrieNode* root = new TrieNode('_');

        for(string &p : products)
            insert(root,p);

        vector<vector<string>> ans;
        string prefix = "";

        for(char ch : searchWord){
            prefix += ch;
            ans.push_back(getSuggestion(root,prefix));
        }

        return ans;
    }
};
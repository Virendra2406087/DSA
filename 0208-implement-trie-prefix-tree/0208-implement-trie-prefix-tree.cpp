class TrieNode{
    public:
    char data;
    bool isTerminal;
    unordered_map<char,TrieNode*>children;
    TrieNode(char val){
        data=val;
        isTerminal=false;
    }
};
void insertWord(TrieNode* root,string word){
    if(word.length()==0){
        root->isTerminal=true;
        return;
    }
    char ch=word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()){
        child=root->children[ch];
    }else{
        child=new TrieNode(ch);
        root->children[ch]=child;
    }
    insertWord(child,word.substr(1));
}
bool searchWord(TrieNode* root,string word){
    if(word.length()==0){
        return root->isTerminal;
    }
    char ch=word[0];
    TrieNode* child;
    if(root->children.find(ch) !=root->children.end()){
        // present
        child=root->children[ch];
    }
    else{
        return false;
    }
    bool recursionAns=searchWord(child,word.substr(1));
    return recursionAns;
}
bool startsWithWord(TrieNode* root,string prefix){
    if(prefix.length()==0){
        return true;
    }
    char ch=prefix[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()){
        child=root->children[ch];
    }else{
        return false;
    }
    bool ans=startsWithWord(child,prefix.substr(1));
    return ans;
}

class Trie {
public:
    TrieNode* root;
    Trie() {
        root =new TrieNode('_');
    }
    
    void insert(string word) {
        insertWord(root,word);
    }
    
    bool search(string word) {
        return searchWord(root,word);
    }
    
    bool startsWith(string prefix) {
        return startsWithWord(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
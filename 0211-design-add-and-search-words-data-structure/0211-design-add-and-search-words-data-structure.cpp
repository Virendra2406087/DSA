class TrieNode {
    public:
    char data;
    unordered_map<char,TrieNode*>children;
    bool isTerminal;

    TrieNode(char val) {
        data=val;
        isTerminal=false;
    }
};

void insertWord(TrieNode* root,string word){
    if(word.size() == 0) {
        root->isTerminal = true;
        return;
    }

    char ch=word[0];
    TrieNode* child;

    if(root->children.find(ch) != root->children.end()) {
        child = root->children[ch];
    } else {
        child = new TrieNode(ch);
        root->children[ch]=child;
    }

    insertWord(child,word.substr(1));
}

bool searchWord(TrieNode* root,string word){
    if(word.size() == 0){
        return root->isTerminal;
    }

    char ch=word[0];

    if(ch != '.') {
        if(root->children.find(ch) != root->children.end()) {
            TrieNode* child = root->children[ch];
            return searchWord(child,word.substr(1));
        } else {
            return false;
        }
    }

    // '.' means any character
    else {
        for(auto &child : root->children) {
            bool recAns = searchWord(child.second,word.substr(1));

            if(recAns == true) {
                return true;
            }
        }

        return false;
    }
}

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root=new TrieNode('$');
    }
    
    void addWord(string word) {
        insertWord(root,word);
    }
    
    bool search(string word) {
        return searchWord(root,word);
    }
};

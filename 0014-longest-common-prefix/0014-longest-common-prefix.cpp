class Solution {
public:
    struct TrieNode {
        bool isTerminal;
        int childCount;
        char data;
        unordered_map<char,TrieNode*>children;
    };
    TrieNode* root;
    TrieNode* getNode(char ch){
        TrieNode *newNode = new TrieNode();

        newNode->isTerminal = false;
        newNode->childCount = 0;
        newNode->data = ch;

        return newNode;
    }
    void insert(TrieNode* root, string str) {
        if(str.size() == 0){
            root->isTerminal=true;
            return;
        }
        char ch=str[0];
        TrieNode *child;
        if(root->children.find(ch) != root->children.end()) {
            child=root->children[ch];
        } else {
            child=getNode(ch);
            root->children[ch]=child;
            root->childCount++;
        }
        insert(child,str.substr(1));
    }
    string findLCP(string &word){
        string ans = "";
        if(root->isTerminal){
            return ans;
        }
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(root->childCount == 1){
                ans.push_back(ch);
                root=root->children[ch];
            } else {
                break;
            }
            if(root->isTerminal){
                break;
            }
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        root=getNode('$');
        for(auto &str : strs) {
            insert(root,str);
        }
        string ans=findLCP(strs[0]);
        return ans;
    }
};
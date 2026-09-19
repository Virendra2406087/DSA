class Solution {
public:
    struct TrieNode {
        char data;
        bool isTerminal;
        unordered_map<char,TrieNode*> children;

        TrieNode(char ch) {
            data = ch;
            isTerminal = false;
        }
    };

    TrieNode* getNode(char ch) {
        TrieNode* temp = new TrieNode(ch);
        return temp;
    }

    void insertWord(TrieNode* root, string word) {
        TrieNode* curr = root;

        for(int i=0;i<word.size();i++) {
            char ch = word[i];

            if(curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = getNode(ch);
            }

            curr = curr->children[ch];
        }

        curr->isTerminal = true;
    }
    vector<string> solve(string& s, int index, TrieNode* root,
                         vector<vector<string>>& dp) {

        if(index == s.size()) {
            return {""};
        }

        if(!dp[index].empty()) {
            return dp[index];
        }

        vector<string> ans;

        TrieNode* curr = root;

        for(int i=index;i<s.size();i++) {

            char ch = s[i];

            if(curr->children.find(ch) == curr->children.end()) {
                break;
            }

            curr = curr->children[ch];

            if(curr->isTerminal) {

                string word = s.substr(index,i-index+1);

                vector<string> temp = solve(s,i+1,root,dp);

                for(int j=0;j<temp.size();j++) {

                    if(temp[j] == "") {
                        ans.push_back(word);
                    }
                    else {
                        ans.push_back(word + " " + temp[j]);
                    }
                }
            }
        }

        return dp[index] = ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = getNode('$');

        // Insert all dictionary words
        for(int i=0;i<wordDict.size();i++) {
            insertWord(root,wordDict[i]);
        }
        vector<vector<string>> dp(s.size());

        return solve(s,0,root,dp);

    }
};
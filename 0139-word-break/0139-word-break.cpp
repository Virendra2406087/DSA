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
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = getNode('\0');

        // Insert all dictionary words
        for(int i=0;i<wordDict.size();i++) {
            insertWord(root,wordDict[i]);
        }

        int n = s.size();

        vector<bool> dp(n+1,false);

        // Empty string can be formed
        dp[0] = true;

        for(int i=0;i<n;i++) {

            if(dp[i] == false) {
                continue;
            }

            TrieNode* curr = root;

            for(int j=i;j<n;j++) {

                char ch = s[j];

                if(curr->children.find(ch) == curr->children.end()) {
                    break;
                }

                curr = curr->children[ch];

                if(curr->isTerminal) {
                    dp[j+1] = true;
                }
            }
        }

        return dp[n];
    }
};
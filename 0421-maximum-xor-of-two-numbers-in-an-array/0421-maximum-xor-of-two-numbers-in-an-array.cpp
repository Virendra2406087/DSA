class Solution {
public:
    struct TrieNode{
        TrieNode* left;
        TrieNode* right;
    };
    void insert(TrieNode* root,int &num){
        TrieNode* pCrawl=root;
        for(int i=31;i>=0;i--){
            int ith_bit=(num>>i)&1;
            if(ith_bit==0){
                if(pCrawl->left == nullptr) {
                    pCrawl->left = new TrieNode();
                }
                pCrawl=pCrawl->left;
            } else {
                if(pCrawl->right == nullptr) {
                    pCrawl->right = new TrieNode();
                }
                pCrawl=pCrawl->right;

            }
        }
    }
    int findmaxXOR(TrieNode* root,int &num){
        int maxXOR=0;
        TrieNode *pCrawl=root;
        for(int i=31;i>=0;i--){
            int ith_bit=(num >> i)&1;
            if(ith_bit == 1){
                if(pCrawl->left != nullptr){
                    maxXOR += pow(2,i);
                    pCrawl=pCrawl->left;
                } else {
                    // maxXOR += pow(2,i)*0=0;
                    pCrawl=pCrawl->right;
                }
            } else{
                if(pCrawl->right != nullptr){
                    maxXOR += pow(2,i);
                    pCrawl=pCrawl->right;
                } else {
                    // maxXOR += pow(2,i)*0=0;
                    pCrawl=pCrawl->left;
                }

            }
        }
        return maxXOR;
    }
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for(int &num:nums){
            insert(root,num);
        }
        int maxResult=0;
        for(int i=0;i<nums.size();i++){
            int temp=findmaxXOR(root,nums[i]);
            maxResult=max(maxResult,temp);
        }
        return maxResult;
    }
};
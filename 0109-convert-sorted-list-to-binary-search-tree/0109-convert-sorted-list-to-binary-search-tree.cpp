/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getLen(ListNode* head){
        int count=0;
        if(head==0){
            return 0;
        }
        while(head != nullptr){
            count++;
            head=head->next;
        }
        return count;
    }
    TreeNode* solve(ListNode* &head,int n){
        if(n<=0){
            return nullptr;
        }
        // LNR
        TreeNode* leftSubTree=solve(head,n/2);
        int element=head->val;
        TreeNode* root=new TreeNode(element);
        root->left=leftSubTree;
        head=head->next;
        TreeNode* rightSubTree=solve(head,n-n/2-1);
        root->right=rightSubTree;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        int n=getLen(head);
        TreeNode* root=solve(head,n);
        return root;
    }
};
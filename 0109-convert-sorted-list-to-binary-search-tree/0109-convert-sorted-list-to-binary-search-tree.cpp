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
        ListNode* temp=head;
        int count=0;
        while(temp !=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    TreeNode* solve(ListNode* &head,int n){
        if(head==NULL){
            return NULL;
        }
        if(n<=0){
            return NULL;
        }
        // LNR
        // L
        TreeNode* leftsubtree=solve(head,n/2);
        // N
        int element=head->val;
        TreeNode* root=new TreeNode(element);
        root->left=leftsubtree;
        head=head->next;
        // R
        TreeNode* rightsubtree=solve(head,n-n/2-1);
        root->right=rightsubtree;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int len=getLen(head);
        TreeNode* root=solve(head,len);
        return root;
    }
};
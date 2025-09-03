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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return head;
        }
        
        if(head->next ==NULL){
           return head;
        }
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr !=NULL){
            if(prev->val !=curr->val){
                curr=curr->next;
                prev=prev->next;
            }else{
                prev->next=curr->next;
                curr->next=NULL;
                delete curr;
                curr=prev->next;
            }
        }
        return head;
    }
};
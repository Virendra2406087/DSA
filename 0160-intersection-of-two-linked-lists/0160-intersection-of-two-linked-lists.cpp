/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head){
        int count=0;
        ListNode* temp=head;
        while(temp != NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL && headB==NULL){
            return NULL;
        }
        int len1=length(headA);
        int len2=length(headB);
        ListNode* temp1=headA;
        ListNode* temp2=headB;
       if(len1>len2){
        for(int i=0;i<len1-len2;i++){
            temp1=temp1->next;
        }
       }else{
        for(int i=0;i<len2-len1;i++){
            temp2=temp2->next;
        }
       }
       while(temp1 != temp2){
        temp1=temp1->next;
        temp2=temp2->next;
       }
       return temp1;
    }
};
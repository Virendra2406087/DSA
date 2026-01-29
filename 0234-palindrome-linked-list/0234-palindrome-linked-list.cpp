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
    int length(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp != NULL){
            count++;
            temp=temp->next;
        }

        return count;
    }
    ListNode* getMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast != NULL && fast->next != NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* reverselist(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr !=NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;  
    }
    bool isPalindrome(ListNode* head) {
        int len=length(head);
        ListNode* mid=getMid(head);
        ListNode* finalMid=NULL;
        if(len & 1){
            finalMid=mid->next;
        }else{
            finalMid=mid;
        }
        finalMid=reverselist(finalMid);
        ListNode* temp=head;
        while(temp != NULL && finalMid != NULL){
            if(temp->val != finalMid->val){
                return false;
            }else{
                temp=temp->next;
                finalMid=finalMid->next;
            }
        }
       return true;
    }
};
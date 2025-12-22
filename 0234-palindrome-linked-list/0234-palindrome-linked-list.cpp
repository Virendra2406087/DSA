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
        int count=0;
        ListNode* temp=head;
        while(temp !=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }

    ListNode* getmid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast !=NULL && fast->next !=NULL){
            slow=slow->next;          
            fast=fast->next->next;    
        }
        return slow;
    }

    ListNode* reverselinkedlist(ListNode* head){
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
        ListNode* mid=getmid(head);
        ListNode* finalmid=NULL;

        if(len & 1){
            finalmid=mid->next;
        }else{
            finalmid=mid;
        }

        finalmid=reverselinkedlist(finalmid);
        ListNode* temp=head;
        while(temp !=NULL && finalmid !=NULL){
            if(temp->val != finalmid->val){
                return false;
            }else{
                temp=temp->next;
                finalmid=finalmid->next;
            }
        }
        return true;  
    }
};

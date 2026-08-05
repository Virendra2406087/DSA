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
    ListNode* reverse(ListNode* head){
        if(head==nullptr){
            return nullptr;
        }
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr != nullptr){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    int length(ListNode* head){
        int count=0;
        ListNode* temp=head;
        while(temp != nullptr){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast != nullptr && fast->next != nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        int n=length(head);
        ListNode* mid=middle(head);
        ListNode* finalMid=nullptr;
        if(n&1){
            finalMid=mid->next;
        } else{
            finalMid=mid;
        }
        ListNode* reversed=reverse(finalMid);
        ListNode* temp1=head;
        ListNode* temp2=reversed;
        while(temp2 != nullptr){
            if(temp2->val != temp1->val){
                return false;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return true;
    }
};
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        ListNode* temp=head;
        while(temp != nullptr && count<k){
            temp=temp->next;
            count++;
        }
            if(count<k){
                return head;
            }
                ListNode* prev=nullptr;
                ListNode* curr=head;
                ListNode* forward=nullptr;
                int i=0;
                while(i<k){
                    forward=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=forward;
                    i++;
                }
                ListNode* recursiveKaHead=reverseKGroup(forward,k);
                head->next=recursiveKaHead;
                return prev;
            
    }
};
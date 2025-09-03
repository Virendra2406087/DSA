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
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL && count < k) {
            count++;
            temp = temp->next;
        }
        
        if (count < k) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        int i = 0;

        while (i < k && curr != NULL) {
            forward = curr->next;   
            curr->next = prev;      
            prev = curr;         
            curr = forward;      
            i++;
        }

        
        head->next = reverseKGroup(forward, k);
        return prev;
    }
};

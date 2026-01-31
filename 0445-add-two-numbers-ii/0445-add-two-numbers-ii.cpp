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
        ListNode* prev = nullptr;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* head = l1;     // preserve head
        ListNode* prev = nullptr;
        int carry = 0;

        while(l1 || l2 || carry){
            int sum = carry;
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;

            carry = sum / 10;
            int digit = sum % 10;

            if(l1){
                l1->val = digit;
            } else {
                prev->next = new ListNode(digit);
                l1 = prev->next;
            }

            prev = l1;
            l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        return reverse(head);
    }
};
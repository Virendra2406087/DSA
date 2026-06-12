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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->next->val >= curr->val) {
                curr = curr->next;
            } else {
                ListNode* prev = dummy;
                while (prev->next && prev->next->val < curr->next->val) {
                    prev = prev->next;
                }
                ListNode* temp = curr->next;
                curr->next = temp->next;
                temp->next = prev->next;
                prev->next = temp;
            }
        }

        return dummy->next;
    }
};
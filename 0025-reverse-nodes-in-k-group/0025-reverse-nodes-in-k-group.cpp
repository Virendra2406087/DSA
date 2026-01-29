class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;

        // count k nodes
        while (temp != NULL && count < k) {
            count++;
            temp = temp->next;
        }

        // if nodes are less than k, return head
        if (count < k) {
            return head;
        }

        // reverse k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        int i = 0;

        while (i < k) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            i++;
        }

        // recursive call
        ListNode* recursionHead = reverseKGroup(curr, k);
        head->next = recursionHead;

        return prev;
    }
};

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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> s;
        ListNode* temp = head;

        while (temp != nullptr) {
            s.push(temp);
            temp = temp->next;
        }

        int count = 0;
        ListNode dummy(0);
        ListNode* newNode = &dummy;

        while (!s.empty()) {
            ListNode* front = s.top();
            s.pop();
            count++;

            if (count == n) {
                continue;
            }

            newNode->next = front;
            newNode = newNode->next;
        }

        newNode->next = nullptr;

        head = reverse(dummy.next);
        return head;
    }
};

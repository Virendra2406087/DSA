class Solution {
public:
    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode* midelement = middle(head);
        queue<ListNode*> q;

        ListNode* temp = head;
        while (temp != NULL){
            if (temp != midelement){
                q.push(temp);
            }
            temp = temp->next;
        }

        ListNode* ans = q.front();
        q.pop();
        ListNode* curr = ans;

        while (!q.empty()){
            curr->next = q.front();
            q.pop();
            curr = curr->next;
        }
        curr->next = NULL;

        delete midelement;
        return ans;
    }
};

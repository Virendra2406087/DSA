class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward = nullptr;

        while (curr != nullptr) {
            bool duplicate = false;
            forward = curr->next;

            while (forward != nullptr && curr->val == forward->val) {
                duplicate = true;
                ListNode* temp = forward;
                forward = forward->next;
                delete temp;
            }

            if (duplicate) {
                ListNode* temp = curr;
                curr = forward;
                delete temp;

                if (prev == nullptr){
                    head = curr;
                }
                else{
                    prev->next = curr;
                }
            } else {
                prev = curr;
                curr = forward;
            }
        }

        return head;
    }
};

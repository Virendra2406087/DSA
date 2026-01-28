class Solution {
public:
    void reverse(ListNode* head, vector<ListNode*>& ans) {
        ListNode* temp = head;
        stack<ListNode*> st;

        while (temp != NULL) {
            st.push(temp);
            temp = temp->next;
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL){
            return NULL;
        }    

        vector<ListNode*> ans;
        reverse(head, ans);

        for (int i = 0; i < ans.size() - 1; i++) {
            ans[i]->next = ans[i + 1];
        }
        ans.back()->next = NULL;

        return ans[0];
    }
};

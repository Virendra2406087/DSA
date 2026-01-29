class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> ans;
        ListNode* temp = head;

        while (temp != NULL) {
            ans.push_back(temp->val);
            temp = temp->next;
        }

        int maxi = 0;
        int i = 0, j = ans.size() - 1;

        while (i < j) {
            maxi = max(maxi, ans[i] + ans[j]);
            i++;
            j--;
        }
        return maxi;
    }
};

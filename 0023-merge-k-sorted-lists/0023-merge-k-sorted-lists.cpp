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

class Compare{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
}; 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare>pq;
        ListNode* head=NULL;
        ListNode* tail=NULL;
        int n=lists.size();
        for(int i=0;i<n;i++){
            ListNode* first=lists[i];
            if(first != NULL){
                pq.push(first);
            }
        }
        while(!pq.empty()){
            ListNode* front=pq.top();
            pq.pop();
            if(head == NULL && tail == NULL){
                head=front;
                tail=front;
            }else{
                tail->next=front;
                tail=front;
            }
            if(front->next != NULL){
                pq.push(front->next);
            }
        }
        return head;
    }
};
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

class compare{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
        ListNode*head=nullptr;
        ListNode* tail=nullptr;
        int totalRows=lists.size();
        for(int i=0;i<totalRows;i++){
            ListNode* first=lists[i];
            if(first != nullptr){
                pq.push(first);
            }
        }
        while(!pq.empty()){
            ListNode* front=pq.top();
            pq.pop();
            if(head==nullptr && tail==nullptr){
                head=front;
                tail=front;
            }else{
                tail->next=front;
                tail=front;
            }
            if(front->next != nullptr){
                pq.push(front->next);
            }
        }
        return head;
    }
};
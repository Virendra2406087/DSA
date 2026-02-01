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
    int getLength(ListNode* head){
        int count=0;
        while(head != nullptr){
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr){
            return nullptr;
        }
        int len=getLength(head);
        int actualRotation=(k%len);
        if(actualRotation==0){
            return head;
        }
        int newNodeLastPos=len-actualRotation-1;
        ListNode* newNodeLast=head;
        for(int i=0;i<newNodeLastPos;i++){
            newNodeLast=newNodeLast->next;
        }
        ListNode* newHead=newNodeLast->next;
        newNodeLast->next=nullptr;

        ListNode* it=newHead;
        while(it->next){
            it=it->next;
        }
        it->next=head;
        return newHead;
    }
};
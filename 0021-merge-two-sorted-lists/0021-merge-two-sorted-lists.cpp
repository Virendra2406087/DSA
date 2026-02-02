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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){
            return list2;
        }
        if(list2==nullptr){
            return list1;
        }
        ListNode* head=nullptr;
        ListNode* tail=nullptr;

        ListNode* temp1=list1;
        ListNode* temp2=list2;
        while(temp1 != nullptr && temp2 != nullptr){
            ListNode* node;
            if(temp1->val<=temp2->val){
                node=temp1;
                temp1=temp1->next;
            }else{
                node=temp2;
                temp2=temp2->next;
            }
            if(head==nullptr){
                head=node;
                tail=node;
            }else{
                tail->next=node;
                tail=node;
            }
        }
        while(temp1 != nullptr){
            tail->next=temp1;
            tail=temp1;
            temp1=temp1->next;
        }
        while(temp2 != nullptr){
            tail->next=temp2;
            tail=temp2;
            temp2=temp2->next;
        }
        return head;
    }
};
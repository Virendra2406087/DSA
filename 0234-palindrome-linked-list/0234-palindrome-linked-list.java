/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode getReverse(ListNode head){
        if(head==null){
            return null;
        }
        ListNode prev=null;
        ListNode curr=head;
        while(curr != null){
            ListNode forward=curr.next;
            curr.next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    public int length(ListNode head){
        int count=0;
        while(head != null){
            count++;
            head=head.next;
        }
        return count;
    }
    public ListNode middle(ListNode head){
        ListNode slow=head;
        ListNode fast=head;
        while(fast != null && fast.next != null){
            fast=fast.next.next;
            slow=slow.next;
        }
        return slow;
    }
    public boolean isPalindrome(ListNode head) {
        int n=length(head);
        ListNode mid=middle(head);
        ListNode finalMid=null;
        if((n&1) == 1){
            finalMid=mid.next;
        } else{
            finalMid=mid;
        }
        ListNode reversed=getReverse(finalMid);
        ListNode temp1=head;
        ListNode temp2=reversed;
        while(temp2 != null){
            if(temp2.val != temp1.val){
                return false;
            }
            temp1=temp1.next;
            temp2=temp2.next;
        }
        return true;
    }
}
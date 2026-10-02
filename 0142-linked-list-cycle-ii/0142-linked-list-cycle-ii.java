/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        Map<ListNode,Boolean> visited= new HashMap<>();
        ListNode temp=head;
        while(temp != null){
            if(visited.getOrDefault(temp,false)==true){
                return temp;
            } else {
                visited.put(temp,true);
                temp=temp.next;
            }
        }
        return null;
    }
}
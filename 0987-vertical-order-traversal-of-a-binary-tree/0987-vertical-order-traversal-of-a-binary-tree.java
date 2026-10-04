/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        Queue<Integer> col = new LinkedList<>();

        q.add(root);
        col.add(0);

        Map<Integer,List<Integer>> distMap = new TreeMap<>();

        while(!q.isEmpty()){
            int size = q.size();

            Map<Integer,List<Integer>> tempMap = new HashMap<>();

            for(int i=0;i<size;i++){
                TreeNode frontNode = q.peek();
                q.remove();

                int hd = col.peek();
                col.remove();

                if(!tempMap.containsKey(hd)){
                    tempMap.put(hd,new ArrayList<>());
                }

                tempMap.get(hd).add(frontNode.val);

                if(frontNode.left != null){
                    q.add(frontNode.left);
                    col.add(hd-1);
                }

                if(frontNode.right != null){
                    q.add(frontNode.right);
                    col.add(hd+1);
                }
            }

            for(int x : tempMap.keySet()){
                Collections.sort(tempMap.get(x));

                if(!distMap.containsKey(x)){
                    distMap.put(x,new ArrayList<>());
                }

                distMap.get(x).addAll(tempMap.get(x));
            }
        }

        List<List<Integer>> ans = new ArrayList<>();

        for(int x : distMap.keySet()){
            ans.add(distMap.get(x));
        }

        return ans;
    }
}
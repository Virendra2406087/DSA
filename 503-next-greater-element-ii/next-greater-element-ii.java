class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        Stack<Integer>s=new Stack<>();
        int []ans=new int[n];
        for(int i=2*n-1;i>=0;i--){
            int idx=i%n;
            while(!s.isEmpty() && nums[s.peek()] <= nums[idx]){
                s.pop();
            }
            if(i < n && !s.isEmpty()){
                ans[idx]=nums[s.peek()];
            }
            else if(i<n) {
                ans[idx]=-1;
            }
            s.push(idx);
        }
        return ans;
    }
}
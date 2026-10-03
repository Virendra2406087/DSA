class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> q = new ArrayDeque<>();
        int n = nums.length;
        int[] ans = new int[n - k + 1];
        int j = 0;

        for(int i = 0; i < k; i++){
            while(!q.isEmpty() && nums[q.peekLast()] < nums[i]){
                q.removeLast();
            }
            q.addLast(i);
        }

        ans[j] = nums[q.peekFirst()];
        j++;

        for(int i = k; i < n; i++){
            
            // Remove index which is outside the window
            if(!q.isEmpty() && q.peekFirst() <= i - k){
                q.removeFirst();
            }

            // Remove smaller elements from back
            while(!q.isEmpty() && nums[q.peekLast()] < nums[i]){
                q.removeLast();
            }

            q.addLast(i);

            ans[j] = nums[q.peekFirst()];
            j++;
        }

        return ans;
    }
}
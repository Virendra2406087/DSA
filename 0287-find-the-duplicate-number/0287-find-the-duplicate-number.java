class Solution {
    public int findDuplicate(int[] nums) {
        Map<Integer,Boolean> visited= new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(visited.getOrDefault(nums[i],false) == true){
                return nums[i];
            } else {
                visited.put(nums[i],true);
            }
        }
        return -1;
    }
}
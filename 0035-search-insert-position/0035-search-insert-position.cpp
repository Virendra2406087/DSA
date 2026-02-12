class Solution {
public:
    int search(vector<int>& nums,int target,int s,int e){
        if(s>e){
            return s;
        }
        int mid=s+(e-s)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[mid]<target){
            return search(nums,target,mid+1,e);
        }else{
            return search(nums,target,s,mid-1);
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        return search(nums,target,0,nums.size()-1);
    }
};
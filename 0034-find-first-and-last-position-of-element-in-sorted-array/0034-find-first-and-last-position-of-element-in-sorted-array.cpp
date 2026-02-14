class Solution {
public:
    int firstOccurance(vector<int>& nums,int target){
        int n=nums.size();
        int fIndex=-1;
        int s=0;
        int e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                fIndex=mid;
                e=mid-1;
            }else if(nums[mid]<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return fIndex;
    }
    int lastOccurance(vector<int>& nums,int target){
        int n=nums.size();
        int lIndex=-1;
        int s=0;
        int e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                lIndex=mid;
                s=mid+1;
            }else if(nums[mid]<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return lIndex;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int first=firstOccurance(nums,target);
        int last=lastOccurance(nums,target);
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};
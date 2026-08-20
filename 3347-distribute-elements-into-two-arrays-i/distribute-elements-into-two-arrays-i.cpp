class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>nums1;
        vector<int>nums2;
        nums1.push_back(nums[0]);
        nums2.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            if(nums1.back()>nums2.back()){
                nums1.push_back(nums[i]);
            }else{
                nums2.push_back(nums[i]);
            }
        }
        for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        return nums1;

    }
};
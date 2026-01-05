class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        vector<int>output;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                output.push_back(nums1[i]);
                i++;
            }else{
                output.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            output.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            output.push_back(nums2[j]);
            j++;
        }
        nums1=output;
    }
};
class Solution {
public:
    void mergeTwo(vector<int>& nums1,int m,vector<int>& nums2,int n,vector<int>& output){
        int i=0;
        int j=0;
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
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>output;
        mergeTwo(nums1,m,nums2,n,output);
        nums1=output;
    }
};
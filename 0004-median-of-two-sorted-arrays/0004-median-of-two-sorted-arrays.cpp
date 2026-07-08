class Solution {
public:
    void merge(vector<int>& nums1, vector<int>& nums2,vector<int>& merged){
        int n=nums1.size();
        int m=nums2.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            merged.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            merged.push_back(nums2[j]);
            j++;
        }

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merged;
        merge(nums1,nums2,merged);
        int n=merged.size();
        if(n&1){
            double ans=merged[n/2];
            return ans;
        } else {
            double ans=(merged[n/2-1]+merged[n/2])/2.0;
            return ans;
        }
    }
};
class Solution {
public:
    void merge(vector<int>& nums1,vector<int>& nums2,vector<int>& sorted){
        int n=nums1.size();
        int m=nums2.size();
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                sorted.push_back(nums1[i]);
                i++;
            }else{
                sorted.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            sorted.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            sorted.push_back(nums2[j]);
            j++;
        }

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>sorted;
        merge(nums1,nums2,sorted);
        int n=sorted.size();
        if(n &1){
            double ans=sorted[n/2];
            return ans;
        }else{
            double ans=(sorted[n/2-1]+sorted[n/2])/2.0;
            return ans;
        }
    }
};
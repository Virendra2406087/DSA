class Solution {
public:
    void merge(vector<int>& nums,int s,int e,int mid){
        int leftArray=mid-s+1;
        int rightArray=e-mid;
        vector<int>left(leftArray);
        vector<int>right(rightArray);
        int mainArray=s;
        for(int i=0;i<leftArray;i++){
            left[i]=nums[mainArray];
            mainArray++;
        }
        mainArray=mid+1;
        for(int i=0;i<rightArray;i++){
            right[i]=nums[mainArray];
            mainArray++;
        }
        int i=0;
        int j=0;
        mainArray=s;
        while(i<leftArray && j<rightArray){
            if(left[i]<right[j]){
                nums[mainArray]=left[i];
                mainArray++;
                i++;
            }else{
                nums[mainArray]=right[j];
                j++;
                mainArray++;
            }
        }
        while(i<leftArray){
            nums[mainArray]=left[i];
            i++;
            mainArray++;
        }
        while(j<rightArray){
            nums[mainArray]=right[j];
            j++;
            mainArray++;
        }

    }
    void merSort(vector<int>& nums,int s,int e){
        if(s>=e){
            return;
        }
        int mid=s+(e-s)/2;
        merSort(nums,s,mid);
        merSort(nums,mid+1,e);
        merge(nums,s,e,mid);
    }
    vector<int> sortArray(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        merSort(nums,s,e);
        return nums;
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int firstLargest=0;
        int secondLargest=0;
        for(int &num:nums){
            if(num>firstLargest){
                secondLargest=firstLargest;
                firstLargest=num;
            } else {
                secondLargest=max(secondLargest,num);
            }
        }
        return (secondLargest-1)*(firstLargest-1);
    }
};
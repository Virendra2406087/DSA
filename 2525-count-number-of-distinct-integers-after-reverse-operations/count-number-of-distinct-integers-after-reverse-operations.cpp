class Solution {
public:
    int reverseValue(int num){
        if(num == 0){
            return 0;
        }
        int totalValue=0;
        while(num > 0){
            int val=num%10;
            totalValue=totalValue*10+val;
            num/=10;
        }
        return totalValue;
    }
    int countDistinctIntegers(vector<int>& nums) {
        set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
            st.insert(reverseValue(nums[i]));
        }
        return st.size();
    }
};
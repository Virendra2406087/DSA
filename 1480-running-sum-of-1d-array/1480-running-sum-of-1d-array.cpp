class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>result;
        result.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            result.push_back(nums[i]+result[i-1]);
        }
        return result;
    }
};
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }else{
                pos.push_back(nums[i]);
            }
        }
        int i=0;
        int j=0;
        while(i<pos.size() && j<neg.size()){
            ans.push_back(pos[i]);
            ans.push_back(neg[j]);
            i++;
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int>rightk;
        vector<int>leftk;
        for(int i=0;i<n-k;i++){
            leftk.push_back(nums[i]);
        }
        for(int i=n-k;i<n;i++){
           rightk.push_back(nums[i]);
        }
        nums.clear();
        nums.insert(nums.end(),rightk.begin(),rightk.end());
        nums.insert(nums.end(),leftk.begin(),leftk.end());
    }
};
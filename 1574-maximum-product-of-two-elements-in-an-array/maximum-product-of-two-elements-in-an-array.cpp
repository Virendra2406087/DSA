class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int>pq;
        for(int& num:nums){
            pq.push(num);
        }
        if(n>=2){
        int num1=pq.top();
        pq.pop();
        int num2=pq.top();
        pq.pop();
        int ans=(num1-1)*(num2-1);
        return ans;
        }else{
            return -1;
        }
    }
};
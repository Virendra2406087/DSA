class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int count=0;
            int nums=i;
            while(nums>0){
                int val=nums%2;
                if(val==1){
                    count++;
                }
                nums/=2;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int j=1;
        int ans=0;
        while(true){
            int multiple=k*j;
            bool found=false;
            for(int x:nums){
                if(x==multiple){
                    found=true;
                    break;
                }
            }
            if(!found){
                return multiple;
            }
            j++;
        }
    }
};
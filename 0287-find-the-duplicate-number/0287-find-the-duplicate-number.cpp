class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        for(int x:nums){
            if(s.count(x)){
                return x;
            }
            s.insert(x);
        }
        return -1;
    }
};
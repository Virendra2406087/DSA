class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int balance=0;
        int difficult=0;
        for(int i=0;i<gas.size();i++){
            if(balance+gas[i]<cost[i]){
                difficult=difficult+balance+gas[i]-cost[i];
                start=i+1;
                balance=0;
            }else{
                balance=balance+gas[i]-cost[i];
            }
            
            // else{
            //     return -1;
            // }
        }
        if(balance+difficult>=0){
                return start;
            }
        return -1;
    }
};
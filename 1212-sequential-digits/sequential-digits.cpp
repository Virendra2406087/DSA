class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int>q;
        for(int i=1;i<=8;i++){
            q.push(i);
        }
        vector<int>result;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            if(temp>=low && temp<=high){
                result.push_back(temp);
            }
            int last_digit=temp%10;
            if(last_digit+1 <=9){
                q.push(temp*10+(last_digit+1));
            }
        }
        return result;
    }
};
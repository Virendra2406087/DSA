class Solution {
public:
    bool isBalanced(string num) {
    vector<int> v;

    for(char c : num){
        v.push_back(c - '0');
    }
        int evenSum=0;
        int oddSum=0;
        for(int i=0;i<v.size();i=i+2){
           evenSum+=v[i];
        }
        for(int i=1;i<v.size();i=i+2){
           oddSum+=v[i];
        }
        if(evenSum != oddSum){
           return false;
        }
        return true;
    }
};
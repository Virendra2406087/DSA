class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result="";
        for(string &word:words){
            int temp=0;
            for(char &ch:word){
                temp+=weights[ch-'a'];
            }
            result+='z'-temp%26;
        }
        return result;
    }
};
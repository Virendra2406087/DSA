class Solution {
public:
    string reverse(string &word){
       int i=0;
       int j=word.size()-1;
       while(i<=j){
        swap(word[i],word[j]);
        i++;
        j--;
       }
       return word;
    }
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> words;
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        string result="";
        for(int i=0;i<words.size();i++){
            string ans=reverse(words[i]);
            if(i != words.size()-1){
                result+=ans+" ";
            }else{
                result+=ans;
            }
        }
        return result;

    }
};
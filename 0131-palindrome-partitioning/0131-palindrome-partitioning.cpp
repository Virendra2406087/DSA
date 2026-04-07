class Solution {
public:
    bool checkPalindrome(string s){
        int i=0, j=s.length()-1;
        while(i<j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    void solve(string &s, int start, vector<string> &path, vector<vector<string>> &result){
        if(start == s.length()){
            result.push_back(path);
            return;
        }

        string pre = "";
        for(int end = start; end < s.length(); end++){
            pre += s[end];
            if(checkPalindrome(pre)){
                path.push_back(pre);
                solve(s, end+1, path, result);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        solve(s, 0, path, result);
        return result;
    }
};
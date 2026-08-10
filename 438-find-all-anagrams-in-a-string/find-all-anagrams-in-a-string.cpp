class Solution {
public:
    bool allOccurance(vector<int>& counter){
        for(int &i:counter){
            if(i != 0){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        vector<int>counter(26,0);
        for(int i=0;i<p.size();i++){
            counter[p[i]-'a']++;
        }
        int i=0,j=0;
        int k=p.size();
        vector<int>ans;
        while(j<n){
            counter[s[j]-'a']--;
            if(j-i+1==k){
                if(allOccurance(counter)){
                    ans.push_back(i);
                }
                counter[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};
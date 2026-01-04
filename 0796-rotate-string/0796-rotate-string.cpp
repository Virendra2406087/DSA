class Solution {
public:
    void rotate(string & s){
        int n=s.length();
        // string a;
        char last=s[n-1];
        for(int i=n-1;i>=0;i--){
            if(i !=0){
                s[i]=s[i-1];
            }else{
                s[0]=last;
            }
        }
        

    }
    bool rotateString(string s, string goal) {
        if(s.length() !=goal.length()){
            return false;
        }
        int n=s.size();
        for(int i=0;i<n;i++){
        rotate(s);
        if(s==goal){
           return true;
           
        }

        }
        return false;
    }
};
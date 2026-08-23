class Solution {
public:
    bool sumGame(string num) {
       int n=num.size();
       int leftKCount = 0; 
       int rightKCount = 0; 
       int leftQmarkCount = 0; 
       int rightQmarkCount = 0; 
       for(int i=0; i < n; i++) {
            if(num[i]=='?'){
                if(i<n/2){
                    leftQmarkCount++;
                } else {
                    rightQmarkCount++;
                }
            } else {
                if(i < n/2){
                    leftKCount += num[i]-'0';
                } else {
                    rightKCount += num[i]-'0';
                }
            }
       }
        int total = leftQmarkCount + rightQmarkCount;
        if(total % 2 == 1){
            return true;
        }

        int LEFT = 2 * leftKCount + 9*leftQmarkCount;
        int RIGHT = 2 * rightKCount + 9*rightQmarkCount;
        if(LEFT == RIGHT) {
            return false;
        }
        return true;
    }
};
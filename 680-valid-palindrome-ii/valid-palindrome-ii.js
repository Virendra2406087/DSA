/**
 * @param {string} s
 * @return {boolean}
 */
 function checkValidPali(s,i,j){
    while(i<=j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
 }
var validPalindrome = function(s) {
    let i=0,j=s.length-1;
    while(i<=j){
        if(s[i] == s[j]){
            i++;
            j--;
        } else {
            let case2 = checkValidPali(s,i,j-1);
            let case1 = checkValidPali(s,i+1,j);
            let ans = case1||case2;
            return ans;
        }
    }
        return true;
};
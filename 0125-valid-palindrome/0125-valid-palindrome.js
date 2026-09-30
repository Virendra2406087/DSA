/**
 * @param {string} s
 * @return {boolean}
 */
 function isValid(c) {
    if(c >= '0' && c <= '9'){
        return true;
    }
    if(c >= 'a' && c <= 'z'){
        return true;
    }
    if(c >= 'A' && c <= 'Z'){
        return true;
    }
    return false;
 }
 function normalisation(s){
    let newStr="";
    for(let i=0;i<s.length;i++){
        let c = s[i];
        if(isValid(c)){
            
            newStr += c.toLowerCase();
        }
    }
    return newStr;
 }
var isPalindrome = function(s) {
    let newStr = normalisation(s);
    let i = 0, j=newStr.length-1;
    while(i<=j){
        if(newStr[i] !== newStr[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
};
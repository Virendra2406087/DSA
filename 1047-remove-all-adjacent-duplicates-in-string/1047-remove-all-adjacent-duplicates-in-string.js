/**
 * @param {string} s
 * @return {string}
 */
var removeDuplicates = function(s) {
    let stack = [];
    for(let i=0;i<s.length;i++){
        if(stack.length == 0){
            stack.push(s[i]);
        } else {
            if(stack[stack.length-1] == s[i]){
                stack.pop();
            } else {
                stack.push(s[i]);
            }
        }
    }
    let ans = "";
    while(stack.length > 0){
        ans += stack[stack.length-1];
        stack.pop();
    }
    ans = ans.split("").reverse().join("");
    return ans;
};
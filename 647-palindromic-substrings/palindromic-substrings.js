/**
 * @param {string} s
 * @return {number}
 */
 function pali(s,i,j) {
    let count =0;
    while(i>=0 && j< s.length && s[i] ==  s[j]){
        count++;
        i--;
        j++;
    }
    return count;
 }
var countSubstrings = function(s) {
    let n = s.length;
    let count = 0;
    for(let entire = 0;entire < n;entire++){
        let i = entire;
        let j = entire;
        let oddcount = pali(s,i,j);
        i=entire;
        j=entire+1;
        let evencount = pali(s,i,j);
        count += oddcount+evencount;
    }
    return count;
};
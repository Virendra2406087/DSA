/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    let str = x.toString();
    let rev=str.split('').reverse().join('');;;;;;;;;;
    return str === rev;
};
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if(s.length !== t.length){
        return false;
    }
    let map = new Map();
    for(let x of s){
        map.set(x,(map.get(x) || 0)+1);
    }
    for(let x of t){
        map.set(x,(map.get(x) || 0)-1);
    }
    for(let [key,value] of map){
        if(value != 0){
            return false;
        }
    }
    return true;
};
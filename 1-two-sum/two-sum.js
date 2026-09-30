/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let arr=[];
    for(let i=0;i<nums.length;i++){
        arr.push([nums[i],i]);
    }
    arr.sort((a,b) => a[0]-b[0]);
    let i=0,j=arr.length-1;
    while(i<j){
        let sum = arr[i][0]+arr[j][0];
        if(sum == target){
            return [arr[i][1],arr[j][1]];
        } else if(sum < target){
            i++;
        } else {
            j--;
        }
    }
    return [];
    
};
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    
    let hash = {};
    let n = nums.length;
    for( let i = 0 ; i < n ; i++ ){
        let x = target - nums[i];
        if( hash[x] !== undefined ) return [hash[x],i];
        hash[nums[i]] = i;
    }
    
    return [];
    
};
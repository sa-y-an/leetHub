/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArrayByParity = function(nums) {
    let arr = [];
    const n = arr.length;
    arr = nums.filter( (x) => x%2 == 0 ).concat(nums.filter( (x) => x%2 != 0));
    return arr;
};

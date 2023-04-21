/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    const n = nums.length;
    let i = 0;
    let ans = 0;    
    while( i < n ){
        let cnt = 0;
        while(nums[i] == 1 ) cnt++, i++;
        ans = Math.max(ans,cnt);
        i++;
    }
    
    return ans;
};
/**
 * @param {string} s
 * @return {number}
 */
var myAtoi = function(s) {
    
    let nums = [];
    let flag = true;
    let start = true;
    const n = s.length;
    let j = 0;
    while(j < n && s[j] == ' ') j++;
    for( let i = j ; i < n ; i++){
        if( nums.length == 0 && start === true && (s[i] == '+' || s[i] == '-') ){
            if( s[i] == '-') flag = false;
            start = false;
        }
        else if( s[i]-'0' >= 0 && s[i]-'0' <= 9 && s[i] != ' ') {
            start = false, nums.push(s[i]-'0');
        }
        else break;
    }
    
    let ans = 0;
    let p = 0;
    for( let i = nums.length-1 ; i >= 0 ; i--){
        ans += nums[i]*Math.pow(10,p);
        p++;
    }
    
    if( !flag) ans *= -1;
    if( ans < -2147483648 ) return -2147483648;
    if( ans > 2147483647 ) return 2147483647;
    
    return ans;
};
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    const n = prices.length;
    let ans = 0;
    for( let i = 1 ; i < n ; i++){
        if( prices[i] > prices[i-1])
            ans += (prices[i] - prices[i-1]);
    }
    return ans;
};
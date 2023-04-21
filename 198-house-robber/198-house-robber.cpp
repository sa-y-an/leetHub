/* DP code
int maxProfit(vector <int> &nums, int idx){

    if( idx < 0 ) return 0;
    if( dp[idx] != -1 ) return dp[idx];
    int pick = nums[idx] + maxProfit(nums, idx-2);
    int not_pick = maxProfit( nums, idx-1);

    return dp[idx] = max(pick, not_pick);

}
*/
// const int n = nums.size();
// vector <int> dp(n,0);
// dp[0] = nums[0];
// for( int i = 1 ; i < n ; i++ ){
//     int take = nums[i];
//     if( i > 1 ) take += dp[i-2];
//     int not_take = dp[i-1];
//     dp[i] = max(take, not_take);
// }

// return dp[n-1];

class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        int prev = nums[0], prev2 = 0;
        for( int i = 1 ; i < n ; i++ ){
            int take = nums[i];
            if( i > 1 ) take += prev2;
            int not_take = prev;
            int curr = max(take, not_take);
            prev2 = prev, prev = curr;
        }
        
        return prev;
    }
};
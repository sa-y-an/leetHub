const int INF = 1e6;
class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n+1][amount+1];
        memset(dp, 0, sizeof(dp));
        for( int j = 1 ; j < amount+1 ; j++) dp[0][j] = INF;
        for( int i = 1 ; i < n+1 ; i++){
            for( int j = 1 ; j < amount+1 ; j++){
                if( j-coins[i-1] >= 0)
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
        int ans = dp[n][amount];
        if( ans >= INF ) return -1;
        return ans;
    }
};
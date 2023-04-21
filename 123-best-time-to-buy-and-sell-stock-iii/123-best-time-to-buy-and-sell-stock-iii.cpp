class Solution {
public:
    int dfs(vector<int>& prices, int dp[][2][3], int idx, int canBuy, int k){
        
        int n = prices.size();
        if( k == 0 || idx == n) return 0;
        if( dp[idx][canBuy][k] != -1 ) return dp[idx][canBuy][k];
        if( canBuy ){
            int buy = -prices[idx] + dfs(prices, dp, idx+1, 0, k);
            int notBuy = dfs(prices, dp,idx+1, 1, k);
            return dp[idx][canBuy][k] = max(buy, notBuy);
        }
        else {
            int sell = prices[idx] + dfs(prices, dp, idx+1, 1, k-1);
            int notSell = dfs(prices, dp, idx+1, 0, k);
            return dp[idx][canBuy][k] = max(sell, notSell);
        }
        
    }
    
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int dp[n][2][3];
        memset(dp, -1, sizeof(dp));
        return dfs(prices, dp, 0, 1, 2);
    }
};
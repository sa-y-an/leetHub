class Solution {
public:
    int dfs(vector <vector<vector<int>>> &dp, vector<int>& prices, int idx, int canBuy, int k){
        int n = prices.size();
        if( k == 0 || idx == n) return 0;
        if( dp[idx][canBuy][k] != -1 ) return dp[idx][canBuy][k];
        if( canBuy ){
            int buy = -prices[idx] + dfs(dp,prices, idx+1, 0, k);
            int notBuy = dfs(dp,prices, idx+1, 1, k);
            return dp[idx][canBuy][k] = max(buy, notBuy);
        }
        else {
            int sell = prices[idx] + dfs(dp,prices, idx+1, 1, k-1);
            int notSell = dfs(dp,prices, idx+1, 0, k);
            return dp[idx][canBuy][k] = max(sell, notSell);
        }    
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector <vector <vector<int>>> dp( n, vector <vector <int>> (2, vector <int> (k+1,-1)));
        return dfs(dp, prices, 0, 1, k);
    }
};
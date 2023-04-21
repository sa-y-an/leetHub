class Solution {
    vector <vector <int>> dp;
    int transactionFee;
public:
    
    int getProfit(vector <int> & prices, int idx, int canBuy ){
        
        int n = prices.size();
        if( idx >= n ) return 0;
        if( dp[idx][canBuy] != -1 ) return dp[idx][canBuy];
        
        if( canBuy ){
            int buy = -prices[idx] + getProfit(prices, idx+1, 0);
            int notBuy = getProfit(prices, idx+1, 1);
            return dp[idx][canBuy] = max(buy, notBuy);
        }
        else{
            int sell = prices[idx] - transactionFee + getProfit(prices, idx+1, 1);
            int notSell = getProfit(prices, idx+1, 0);
            return dp[idx][canBuy] = max(sell, notSell);
        }   
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        transactionFee = fee;
        dp.resize(n, vector <int> (2,-1));
        return getProfit(prices, 0, 1);
    }
};
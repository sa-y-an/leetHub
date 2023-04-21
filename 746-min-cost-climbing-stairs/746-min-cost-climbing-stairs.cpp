class Solution {
    vector <int> dp;
public:
    
    int minCost(vector <int> &cost, int idx ){
        
        int n = cost.size();
        if( idx >= n )
            return 0;
        
        if( dp[idx] != -1 )
            return dp[idx];
        
        return dp[idx] = cost[idx] + min(minCost(cost,idx+1),minCost(cost,idx+2));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        dp.resize(n, -1);
        
        return min(minCost(cost,0),minCost(cost,1));
    }
};
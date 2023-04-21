class Solution {
    vector <vector<int>> dp;
public:
    int maxVal(vector<vector<int>>& piles, int idx, int k){
        
        if( k <= 0 || idx < 0 )
            return 0;
        if( dp[idx][k] != -1 )
            return dp[idx][k];
        
        int m = piles[idx].size();
        int curr = 0, ans = 0;
        for( int i = 0 ; i < min(m,k) ; i++){
            curr += piles[idx][i];
            ans = max(ans, curr+maxVal(piles,idx-1,k-i-1));
        }
        
        return dp[idx][k] = max(ans,maxVal(piles,idx-1,k));
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        dp.resize(n,vector <int> (k+1,-1));
        return maxVal(piles,n-1,k);
    }
};
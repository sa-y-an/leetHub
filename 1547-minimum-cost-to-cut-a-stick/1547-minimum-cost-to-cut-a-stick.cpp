const int INF = 1e9;
class Solution {
    vector<vector<int>> dp;
public:
    
    int dfs(vector <int> &cuts , int l , int r ){
        
        if( r-l <= 1 )
            return 0;
        if( dp[l][r] != -1 )
            return dp[l][r];
        
        dp[l][r] = INF;
        for( int k = l+1 ; k < r ; k++){
            dp[l][r] = min((cuts[r]-cuts[l]) + dfs(cuts,l,k) + dfs(cuts,k,r),
                           dp[l][r]);
                           
        }
        
        return dp[l][r];
    }
    
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        dp.resize(m, vector <int> (m,-1));
        return dfs(cuts, 0, cuts.size()-1);
    }
};
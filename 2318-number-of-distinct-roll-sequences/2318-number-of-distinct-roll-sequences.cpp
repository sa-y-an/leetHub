const int N = 1e4+5;
const int m = 1e9+7;
int dp[N][8][8];
class Solution {
    int lim;
public:
    
    int dfs( int idx, int prev1, int prev2){
        
        if( idx == lim+1 )
            return 1;
        
        if( dp[idx][prev1][prev2] != -1 )
            return dp[idx][prev1][prev2];
        
        int ans = 0;
        for( int i = 1 ; i < 7 ; i++){
            if ( ( prev1 == 0 || __gcd(i,prev1) == 1 ) and ( prev1 != i ) and (prev2 != i ) )
                ans = (ans%m + dfs(idx+1,i,prev1)%m)%m;
        }
        
        return dp[idx][prev1][prev2] = ans;
        
    }
    
    int distinctSequences(int n) {
        
        memset(dp, -1, sizeof(dp));
        lim = n;
        return dfs(1,0,0);
    }
};
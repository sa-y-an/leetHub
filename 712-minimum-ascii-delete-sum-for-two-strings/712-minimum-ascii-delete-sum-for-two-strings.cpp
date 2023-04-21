class Solution {
public:
    int minimumDeleteSum(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for( int i = 1 ; i <= n ; i++){
            for( int j = 1 ; j <= m ; j++){
                if( text1[i-1] == text2[j-1]) dp[i][j] = int(text1[i-1]) + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        long lcs = dp[n][m];
        
        int ans = accumulate(text1.begin(),text1.end(),0*1LL)+
            accumulate(text2.begin(),text2.end(),0*1LL) - 2*lcs;
        
        return ans;
    }
};
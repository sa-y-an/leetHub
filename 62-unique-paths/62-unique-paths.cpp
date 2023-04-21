/*
int uniquePaths(int m, int n) {
    if( m == 1 and n == 1 ) return 1;
    if( m < 1 or n < 1 ) return 0;
    if( dp[m][n] != -1 ) return dp[m][n];
    return dp[m][n] = uniquePaths(m-1,n) + uniquePaths(m,n-1);
}
*/

class Solution {
public:
    int uniquePaths(int m , int n ){
        vector <vector <int>> dp(n, vector <int> (m,1));
        
        for( int i = 1 ; i < n ; i++){
            for( int j = 1; j < m ; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[n-1][m-1];
    }
};
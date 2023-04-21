class Solution {
public:
    string longestPalindrome(string s) {
        
        string z = s;
        reverse(z.begin(),z.end());
        int n = s.size();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        pair <int, int> idx;
        int cnt = 0;
        for( int i = 1 ; i <= n ; i++){
            for( int j = 1; j <= n ; j++){
                if( s[i-1]== z[j-1] ) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if( cnt < dp[i][j] and i-dp[i][j]== n-j){ // i - dp[i][j] == n- j 
                        cnt = dp[i][j];
                        idx = {i,j};
                    }
                }
            }
        }
        
        auto [i,j] = idx;
        string ans;
        while( i > 0 and j > 0 and dp[i][j] > 0 ){
            ans.push_back(s[i-1]);
            i--,j--;
        }
        
        return ans;
    }
};
const int m = 1e9+7;
class Solution {
public:
    int distinctSubseqII(string s) {
        
        int n = s.size();
        vector <int> lastSeen(26,-1);        
        
        vector <int> dp(n+1,0);
        dp[0] = 1;
        
        for( int i = 0 ; i < n ; i++){
            char ch = s[i];
            dp[i+1] = (2*dp[i])%m;
            if( lastSeen[ch-'a'] != -1 )
                dp[i+1] = (dp[i+1]%m - dp[lastSeen[ch-'a']]%m + m)%m;
            lastSeen[ch-'a'] = i;
        }
        
        return dp[n]-1;   
    }
};

class Solution {
    vector <vector <int>> dp;
public:
    
    int match(string &s, string &t, int i, int j){
        
        if( j < 0 ) return 1;
        if( i < 0 ) return 0;
        if( dp[i][j] != -1 ) return dp[i][j];
        
        if( s[i] == t[j] )
            return dp[i][j] = match(s,t,i-1,j-1) + match(s,t,i-1,j);
        
        return dp[i][j] = match(s,t,i-1,j);
    }
    
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        dp.resize(n, vector <int> (m,-1));
        return match(s,t,n-1,m-1);
    }
};
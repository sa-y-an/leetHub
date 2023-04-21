class Solution {
    vector <vector <int>> dp;
public:
    
    bool match(string &s, string &p, int i, int j ){ 
        if( i == 0 || j == 0 ) {
            if( j >= 1 and p[j-1] == '*') return dp[i][j] = match(s,p,i,j-2);
            return dp[i][j] = (i == j);
        }
        if( dp[i][j] != -1 ) return dp[i][j];
        
        bool ans = false;
        if( s[i-1] == p[j-1] or (j >= 1 and p[j-1] == '.'))
            ans |= (bool) match(s,p, i-1, j-1);
        
        if( p[j-1] == '*') {
            if( p[j-2] == '.' or p[j-2] == s[i-1] )
               ans |= (bool) (match(s,p,i-1,j-1) || match(s,p,i,j-2) || match(s,p,i-1,j));
            else 
               ans |= (bool) match(s,p,i,j-2);
        }
        return dp[i][j] = ans;
    }
    
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        dp.resize(n+1, vector <int> (m+1,-1));
        bool ans= match(s,p, n, m);      
        return ans;
    }
};
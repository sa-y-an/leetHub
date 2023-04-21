class Solution {
    vector <vector<int>> dp;
    int startOfStar;
public:
    
    bool match(const string &s, const string &p, int i, int j){
        
        if( i < 0 and j < 0 ) return true;
        if( i < 0 and j <= startOfStar ) return true;
        if( i < 0 || j < 0) return false;
        if( dp[i][j] != -1 ) return dp[i][j];
        
        if( s[i] == p[j] || p[j] == '?') 
            return dp[i][j] = match(s,p,i-1,j-1);
        else if( p[j] == '*')
            return dp[i][j] = match(s,p,i-1,j-1) || match(s,p,i-1,j) || match(s,p,i,j-1);
        
        return dp[i][j] = false;
    }
    
    
    bool isMatch(string s, string p) {
        
        int n = s.size(), m = p.size();
        dp.resize(n, vector <int> (m,-1));
        int i = 0;
        while( i < m and p[i] == '*') i++;
        startOfStar = i-1;
        return match(s,p, n-1,m-1);   
    }
};
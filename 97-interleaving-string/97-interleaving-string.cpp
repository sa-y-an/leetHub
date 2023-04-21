class Solution {
    vector <vector <int>> dp;
public:
    
    bool match(string &s1, string &s2, string &s3, int l , int r, int idx ){
        
        if( idx < 0 )
            return l < 0 and r < 0;
        if( (l < 0 and r < 0) or l < -1 or r < -1 )
            return false;
        
        if( dp[l+1][r+1] != -1 )
            return dp[l+1][r+1];
        
        bool ans = false;
        
        if( l >= 0 and s3[idx] == s1[l])
            ans |= match(s1,s2,s3,l-1,r,idx-1);
        
        if( r >= 0 and s3[idx] == s2[r])
            ans |= match(s1,s2,s3,l,r-1,idx-1);
        
        return dp[l+1][r+1] = ans;
        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), 
            n2 = s2.size(),
            n3 = s3.size();
        
        dp.resize(n1+1, vector <int> (n2+1, -1));
        return match(s1,s2,s3,n1-1,n2-1,n3-1);
    }
};
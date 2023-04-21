class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int dp[n+1][m+1];
        memset(dp,0 , sizeof(dp));
        
        for( int i = 1; i <= n ; i++){
            for( int j = 1 ; j <= m ; j++){
                if( str1[i-1] == str2[j-1] ) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        vector <int> lcs1, lcs2;
        int i = n, j = m;
        
        while( i > 0 and j > 0 and dp[i][j] > 0 ){
            if( str1[i-1] == str2[j-1] ) lcs1.push_back(i-1), lcs2.push_back(j-1), i--, j--;
            else if( dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
        
        reverse(lcs1.begin(),lcs1.end());
        reverse(lcs2.begin(),lcs2.end());
        
        
        int sz = lcs1.size(), l = 0 , r = 0;
        string ans;
        for( int idx = 0 ; idx < sz ; idx++){
            while( l < lcs1[idx] ) ans.push_back(str1[l]), l++;
            l = lcs1[idx]+1;
            while( r < lcs2[idx]) ans.push_back(str2[r]), r++;
            r = lcs2[idx]+1;
            ans.push_back(str1[lcs1[idx]]);
        }
        
        while( l < n ) ans.push_back(str1[l]), l++;
        while( r < m ) ans.push_back(str2[r]), r++;
        
        
        return ans;
    }
};
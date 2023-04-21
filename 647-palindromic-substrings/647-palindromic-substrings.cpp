class Solution {
    vector <vector <int>> dp;
public:
    
    bool isPalindrome(int l, int r, string &s){

        if( l > r ) return true;
        if( dp[l][r] != -1 ) return dp[l][r];
        if( s[l] != s[r]  ) return false;
        return dp[l][r] = isPalindrome(l+1,r-1,s);
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        dp.resize(n, vector <int> (n,-1));
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j <= i ; j++){
                if( isPalindrome(j,i,s) ) ans++;
            }
        }
        return ans;
    }
};
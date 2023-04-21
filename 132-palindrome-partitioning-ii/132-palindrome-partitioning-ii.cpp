const int INF = 1e8;
class Solution {
    vector <vector <int>> dp;
    vector <vector <int>> bdp;
public:
    
    bool isPalindrome(const string &s, const int &l,const int &r){
        
        if( bdp[l][r] != -1 )
            return bdp[l][r];
        int i = l, j = r;
        bool ans = true;
        while( i < j ){
            if( s[i++] != s[j--]){
                ans = false;
                break;
            }
        }
        return bdp[l][r] = ans;
    }
    
    int dfs( const string &s, int l, int r){
        
        int n = s.size();
        if( l == n )
            return 0;
        
        if( dp[l][r] != -1 )
            return dp[l][r];
        
        int ans = INF;
        if( isPalindrome(s,l,r)) 
            ans = 0;
        else{
            for( int i = l ; i < r ; i++){
                if( isPalindrome(s,l,i) )
                    ans = min(ans, 1 + dfs(s,i+1,r));
            }
        }
        return dp[l][r] = ans;
    }
    
    int minCut(string &s) {
        int n = s.size();
        dp.resize(n, vector <int> (n,-1));
        bdp.resize(n,vector <int> (n,-1));
        return dfs(s,0,n-1);
    }
};
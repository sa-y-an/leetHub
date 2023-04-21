/*
int minSum(vector<vector<int>>& triangle, int idx = 0 , int prev = 0 ){

    int n = triangle.size();
    if( idx >= n ) return 0;
    if( dp[idx][prev] != -1 ) return dp[idx][prev];

    int ans = triangle[idx][prev] + minSum(triangle, idx+1 , prev);
    if( prev+1 < triangle[idx].size() ) 
        ans = min(triangle[idx][prev+1] + minSum(triangle,idx+1, prev+1), ans);

    return dp[idx][prev] = ans;

}
*/
const int INF = 1e5+7;

class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), m = triangle[n-1].size();
        vector <vector <int>> dp(n, vector <int> (m,0));
        
        for( int i = n-1 ; i >= 0 ; i--){
            for( int j = m-1 ; j >= 0 ; j--){    
                int first = INF, second = INF;
                if( j < triangle[i].size()) first = triangle[i][j];
                if( i+1 < n ) first += dp[i+1][j];
                
                if( j+1 < triangle[i].size() ) second = triangle[i][j+1];
                if( i+1 < n and j+1 < m ) second += dp[i+1][j+1];
                dp[i][j] = min(first, second);
            }
        }
        
        return dp[0][0];
    }
};
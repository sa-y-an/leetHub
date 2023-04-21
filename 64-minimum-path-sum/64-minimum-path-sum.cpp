/*
int minPath(vector <vector <int>> &grid, int x, int y ){
    if( x < 0 or y < 0 ) return INT_MAX;
    if( x == 0 and y == 0 ) return grid[0][0];
    if( dp[y][x] != -1 ) return dp[y][x];
    int ans = grid[y][x];
    ans += min(minPath(grid, x-1, y), minPath(grid, x, y-1));
    return dp[y][x] = ans;

}
*/
const int INF = 1e9+7;
class Solution {
    vector <vector <int>> dp;
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector <vector <int>> dp(n , vector <int> (m,INF));
        dp[0][0] = grid[0][0];
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                dp[i][j] = grid[i][j];
                int curr = INF;
                i > 0 ? curr = min(curr, dp[i-1][j]) : curr;
                j > 0 ? curr = min(curr, dp[i][j-1]) : curr;
                curr < INF ? dp[i][j] += curr : curr;
            }
        }
        
        return dp[n-1][m-1];
    }
};
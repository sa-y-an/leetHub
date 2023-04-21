/*

- 3D DP
- Idea is to make two persons start from (0,0) and make them traverse on two alternate or same path
to collect as many cherry as possible

- Optimization
- x1+y1 = x2 + y2 ( as we can only move down and right )

*/

const int INF = 1e5;
class Solution {
    int dp[52][52][52];
public:
    
    int maxpoints(vector<vector<int>>& grid, int sx, int sy, int ex){
        
        int n = grid.size();
        
        int ey = sx+sy-ex;
        if( sx == n or sy == n or ex == n or ey == n or grid[sy][sx] == -1 or grid[ey][ex] == -1 ) 
            return -1*INF;

        if( sx == n-1 and sy == n-1 ) return grid[sy][sx];
        if( ex == n-1 and ey == n-1 ) return grid[ey][ex];
        if( dp[sy][sx][ex] != -1 ) return dp[sy][sx][ex];
        
        int ans = 0;
        
        if( sx == ex and sy == ey ) ans = grid[ey][ex];
        else ans = grid[ey][ex] + grid[sy][sx];

        int addon = -1*INF;        
        addon = max(addon, maxpoints(grid, sx,sy+1, ex));
        addon = max(addon, maxpoints(grid, sx+1,sy, ex));
        addon = max(addon, maxpoints(grid, sx,sy+1, ex+1));        
        addon = max(addon, maxpoints(grid, sx+1,sy, ex+1));

        return dp[sy][sx][ex] = ans+addon;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        if( grid[0][0] == -1 or grid[n-1][n-1] == -1 ) return 0;
        memset(dp,-1, sizeof(dp));
        int ans = maxpoints(grid, 0, 0, 0 );
        if( ans < 0 ) return 0;
        else return ans;
        
    }
};



vector <int> mover = {-1,0,1};
class Solution {
    int dp[72][72][72];
public:

    int maxPoints(vector<vector<int>> &grid,
                  int i, int a, int b){

        int n = grid.size(), m = grid[0].size();
        if( i >= n ) return 0;
        if( a < 0 or a >= m or b < 0 or b >= m ) return 0;
        if( dp[i][a][b] != -1 ) return dp[i][a][b];
        if( i == n-1 ) {
            if(a == b ) return grid[i][a];
            else return grid[i][a] + grid[i][b];
        }

        int ans = 0;
        if( a == b ) ans += grid[i][a];
        else ans += grid[i][a] + grid[i][b];

        int curr = 0;
        for( auto move_a : mover ){
            for( auto move_b : mover ){
                curr = max(curr, maxPoints(grid, i+1, a+move_a, b+move_b));
            }
        }

        return dp[i][a][b] = ans+curr;
    }

    
    int cherryPickup(vector<vector<int>>& grid) {
        int c = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return maxPoints(grid, 0, 0, c-1);    
    }
};
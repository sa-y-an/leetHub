class Solution {
    vector <vector <int>> dp;
public:
    
    int dfs(vector<vector<int>>& obstacleGrid, int y, int x){
        
        if( y < 0 or x < 0 or obstacleGrid[y][x] == 1 ) return 0;
        if( y == 0 and x == 0 ) return dp[y][x] = 1;
        if( dp[y][x] != -1 ) return dp[y][x];
        
        
        return dp[y][x] = dfs(obstacleGrid, y-1, x) + dfs(obstacleGrid, y, x-1);
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if( obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;
        dp.resize(n, vector <int> (m,-1));
        return dfs(obstacleGrid,n-1, m-1);
    }
};
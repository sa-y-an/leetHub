const int mod = 1e9+7;
vector <pair<int,int>> dz = {{1,0},{0,1},{-1,0},{0,-1}};
class Solution {
    vector <vector <int>> dp;
public:
    
    int dfs(vector<vector<int>> &grid, int y, int x){
        
        if( dp[y][x] != -1 )
            return dp[y][x];
        
        int n = grid.size(), m = grid[0].size();
        int ans = 1;
        for( auto &[dx,dy] : dz ){
            int i = y + dy , j = x + dx;
            if( i < n and i >= 0 and j >= 0 and j < m and grid[i][j] < grid[y][x] )
                ans = (ans%mod + dfs(grid,i,j)%mod)%mod; 
        }
        
        return dp[y][x] = ans;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        dp.resize(n, vector <int> (m,-1));
        
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                if( dp[i][j] == -1 )
                    dfs(grid,i,j);
            }
        }
        
        int ans = 0;
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                ans = (ans%mod + dp[i][j]%mod)%mod;
            }
        }
        
        return ans;
    }
};
vector <pair<int, int>> dz = {{1,0}, {0,1},{-1,0},{0,-1}};
class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, int y, int x){
        
        int n = grid.size(), m = grid[0].size();
        if( y >= n or x >= m or y < 0 or x < 0 or grid[y][x] != 1 ) return;
        grid[y][x] = 2;
        
        for( auto &[dy,dx] : dz){
            int i = y+dy, j = x+dx;
            dfs(grid, i, j);
        }
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        for( int x = 0 ; x < m ; x++) {
            if( grid[0][x] == 1 ) dfs(grid,0,x);
            if( grid[n-1][x] == 1 ) dfs(grid,n-1,x);
        }
        
        for( int y = 0 ; y < n ; y++){
            if( grid[y][0] == 1 ) dfs(grid, y,0);
            if( grid[y][m-1] == 1) dfs(grid,y,m-1);
        }
        
        int ans = 0;
        for( int i = 1; i < n-1 ; i++){
            for( int j = 1; j < m-1 ; j++){
                if( grid[i][j] == 1) ans++;
            }
        }
        
        return ans;
        
    }
};
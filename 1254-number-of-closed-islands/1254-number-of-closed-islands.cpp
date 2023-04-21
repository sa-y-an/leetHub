vector <pair <int,int>> mover = {{1,0},{0,1},{-1,0},{0,-1}};

class Solution {
public:
    
    void color( vector<vector<int>>& grid, int x, int y){
        
        int n = grid.size(), m = grid[0].size();        
        grid[y][x] = 2;
        
        for( auto &[dx,dy] : mover ){
            int j = x + dx, i = y + dy;
            if( i < n and i >= 0 and j < m and j >= 0 and grid[i][j] == 0 )
                color(grid,j,i);
        }
        
    }
    
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        for( int i = 0 ; i < n ; i++){
            if( grid[i][0] == 0 )
                color( grid, 0, i);
            if( grid[i][m-1] == 0 )
                color(grid,m-1,i);
        }
        
        for( int i = 1; i < m-1 ; i++){
            if( grid[0][i] == 0 )
                color(grid,i,0);
            if( grid[n-1][i] == 0 )
                color(grid,i,n-1);
        }
        
        
        int ans = 0;
        for( int i = 1 ; i < n-1 ; i++){
            for( int j = 1 ; j < m-1 ; j++){
                if( grid[i][j] == 0 ){
                    color(grid,j,i);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
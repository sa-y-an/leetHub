vector <pair<int, int> > movements = {{1,0},{0,1},{-1,0},{0,-1}};

class Solution {
public:
    
    
    int dfs(vector <vector <int>> &grid, int y, int x){
        
        int n = grid.size(), m = grid[0].size();
        if( y >= n || x >= m || y < 0 || x < 0 || grid[y][x] != 1 ) return 0;
        grid[y][x] = 2;
        int ans = 1;
        for( auto &move : movements ){
            ans += dfs(grid, y+move.second , x + move.first);
        }
        
        return ans;
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       
        int n = grid.size(), m = grid[0].size(), ans = 0;
        
        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < m ; j++){
                if( grid[i][j] == 1) 
                    ans = max(dfs(grid, i, j), ans);
            }
        }
        
        return ans;
    }
};
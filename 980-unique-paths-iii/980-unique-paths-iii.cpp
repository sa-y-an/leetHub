vector <pair<int,int>> mover = {{-1,0},{0,-1},{1,0},{0,1}};

class Solution {
    int m , n, non_obstacle;
    vector <vector <bool>> visited;
public:
    
    int dfs(vector<vector<int>>& grid, int x, int y, int acc = 1 ){
        
        if( x < 0 or y < 0 or x >= m or y >= n or grid[y][x] == -1)
            return 0;
        if( grid[y][x] == 2 ) return acc == non_obstacle ? 1: 0;
        grid[y][x] = -1;
        int ans = 0;
        for( auto &move: mover ){
            ans += dfs(grid, x+move.first, y + move.second, acc+1);
        }
        grid[y][x] = 0;
        return ans;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size() , m = grid[0].size();
        visited.resize(n, vector <bool> (m ,false));
        non_obstacle = 0;
        int x = 0, y = 0;
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                if( grid[i][j] == 1 ) x = j , y = i ; 
                if( grid[i][j] != -1 ) non_obstacle++;
            }
        }

        return dfs(grid,x,y);
    }
};
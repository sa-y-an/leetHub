vector <pair<int,int>> dz = {{1,0},{0,1},{-1,0},{0,-1}};

class Solution {
    vector <vector <bool>> visited;
public:
    
    bool ifCycle(vector <vector <char>> &grid, char ch, int py, int px,int y, int x){
    
        if( visited[y][x] )
            return true;
        
        visited[y][x] = true;
        
        int n = grid.size(), m = grid[0].size();
        bool ans = false;
        
        for( auto &[dy,dx] : dz ){
            int i = y + dy, j = x + dx;
            if( i < n and i >= 0 and j < m and j >= 0 and grid[i][j] == ch  ){
                if( i == py and j == px ) // child == grandparent
                    continue;
                ans |= ifCycle(grid,ch,y,x,i,j);
            }
        }
        
        return ans;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        visited.resize(n, vector <bool> (m,false));
        
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                if( !visited[i][j] ){
                    if( ifCycle(grid,grid[i][j], -1,-1,i,j) ){
                        return true;
                    }
                }
            }
        }
            
        return false;
    }
};
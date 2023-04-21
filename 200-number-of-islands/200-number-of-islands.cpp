vector <pair <int,int>> mover = {{-1,0},{0,-1},{0,1},{1,0}};
int X, Y;
bool visited[310][310];

class Solution {
public:
        
    struct children{

        int x;
        int y;
        children(int _x , int _y ){
            x = _x, 
            y = _y;
        }

        bool isValid(vector<vector<char>>& grid){
            if( x < 0 or y < 0 or x >= X or y >= Y ) return false;
            if( visited[y][x]) return false;
            if( grid[y][x] == '0') return false;
            return true;
        }

    };
    
    
        
    void dfs(int x, int y,vector<vector<char>>& grid){
        visited[y][x] = true;
        for( auto move : mover ){
            children child(x+move.first, y+move.second);
            if ( not child.isValid(grid)) continue;
            dfs(child.x, child.y, grid);
        }   
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        memset(visited, false, sizeof(visited));
        
        int cntDfs = 0;
        X = grid[0].size(), Y = grid.size();
        
        for(int y = 0 ; y < Y ; y++){
            for( int x = 0 ; x < X ; x++){
                if( visited[y][x] or grid[y][x] == '0') continue;
                dfs(x,y,grid);
                cntDfs++;
            }
        }
        
        return cntDfs;
        
    }
};
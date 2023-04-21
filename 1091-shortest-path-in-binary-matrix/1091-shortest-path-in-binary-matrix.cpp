const vector <pair<int, int>> movements = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if( grid[0][0] == 1 or grid[n-1][n-1] == 1) return -1;
        if( n == 1 ) return 1;
        queue <pair <int, int>> q;
        int level = 1;
        q.push({0,0});
        grid[0][0] = 1;
        
        while( !q.empty()){
            for( int sz = q.size(); sz-- ; q.pop()){
                auto [y,x] = q.front();
                if( x == n-1 and y == n-1 ) return level;
                for( auto &[dy,dx] : movements ){
                    int cy = y+dy, cx = x+dx;
                    if( cy < 0 || cx < 0 || cx >= n || cy >= n || grid[cy][cx] == 1 ) continue;
                    grid[cy][cx] = 1;
                    q.push({cy,cx});
                }
            }
            level++;
        }
        return -1;
    }
};
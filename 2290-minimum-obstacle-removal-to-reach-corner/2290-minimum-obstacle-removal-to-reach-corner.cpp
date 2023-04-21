vector <pair<int,int>> movements = {{1,0},{0,1},{0,-1},{-1,0}};
const int INF = 1e6+10;
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> distance(n ,vector <int> (m ,INF));
        set <tuple<int,int,int>> s;
        s.insert({grid[0][0],0,0});
        
        
        while( !s.empty()){
            auto temp = s.begin();
            auto [c,y,x] = *temp;
            if( y == n-1 and x == m-1 ) return c;
            s.erase(temp);
            grid[y][x] = 2;
            for( auto [dy,dx] : movements){
                int cx = dx+x , cy = dy+y;
                if( cx < 0 || cy < 0 || cy >= n || cx >= m || grid[cy][cx] == 2 ) continue;
                if( distance[cy][cx] >  c + grid[cy][cx] ){
                    distance[cy][cx] = c + grid[cy][cx];
                    s.insert({c + grid[cy][cx], cy, cx});
                }
            } 
        }
        
        return distance[n-1][m-1];
    }
};
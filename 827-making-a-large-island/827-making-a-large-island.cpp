struct dsu{
private:
    vector <int> parent, _size;
public:
    
    dsu(int n){
        parent.resize(n,-1);
        _size.resize(n,1);
        for( int i = 0 ; i < n ; i++) parent[i] = i;
    }

    int ufind(int x){
        if( parent[x] == x) return x;
        return parent[x] = ufind(parent[x]);
    }

    void uunion(int a, int b){ 
        a = ufind(a) , b = ufind(b);
        if( a == b ) return;
        if( _size[a] < _size[b]) swap(a,b);
        parent[b] = a;
        _size[a] += _size[b];
    }
    
    pair<int,int> getSize(int x){
        x = ufind(x);
        return {x,_size[x]};
    }
};


vector <pair<int,int>> mover = {{1,0},{-1,0},{0,1},{0,-1}};

class Solution {
    int n;
public:
    
    int hash(int y, int x){
        return x + n*y;
    }
    
    
    void dfs(vector<vector<int>>& grid, dsu &graph, int y, int x, int pary = -1, int parx = -1 ){

        if( y >= n or x >= n or y < 0 or x < 0 or grid[y][x] != 1 ) return ;
        grid[y][x] = 2;
        
        if( parx != -1 and pary != -1 ){
            graph.uunion(hash(y,x), hash(pary,parx));
        }
        
        for( auto &move : mover ){
            dfs(grid,graph,y+move.first,x+move.second, y,x);
        }
        
    }    
    
    
    pair<int,int> getCompSize(int y, int x, dsu &graph, vector<vector<int>>& grid){
        
        if( y >= n or x >= n or y < 0 or x < 0 ) return {-1,0};
        
        if( grid[y][x] == 0 ) return {-1,0};
        int node = hash(y,x);
        return graph.getSize(node);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        
        n = grid.size();
        int acc = 0;
        
        dsu graph(n*n);
        
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < n ; j++){
                if( grid[i][j] == 1 )
                    dfs(grid,graph, i, j);
            }
        }
          
        int ans = 0;
        
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < n ; j++){
                unordered_set <int> leader;
                if( grid[i][j] == 0 ){
                    int compSize = 1;
                    for( auto &move : mover ){
                        auto df = getCompSize(i+move.first, j+move.second, graph, grid);
                        if( leader.count(df.first) > 0 ) continue;
                        leader.insert(df.first);
                        compSize += df.second;
                    }
                    ans = max(ans, compSize);
                }
            }
        }
        
        if( ans == 0 ) ans = n*n;
        return ans;
        
    }
};
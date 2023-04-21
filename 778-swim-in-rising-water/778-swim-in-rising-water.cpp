vector <pair<int,int>> mover = {{0,1},{1,0},{-1,0},{0,-1}};
struct DSU{
private :
    vector <int> _parent, _size;
public :
    DSU(int n){
        _parent.resize(n,0);
        for( int i = 0 ; i < n ; i++)
            _parent[i] = i;
        _size.resize(n,1);
    }
    
    int ufind(int x){
        if( x == _parent[x] )
            return x;
        return _parent[x] = ufind(_parent[x]);
    }
    
    void uunion(int a,int b){
        a = ufind(a) , b = ufind(b);
        if( a == b )
            return;
        if( _size[a] < _size[b] )
            swap(a,b);
        _size[a] += _size[b];
        _parent[b] = a;
    }
    
    bool isConnected(){
        int n = _parent.size()-1;
        return ufind(0) == ufind(n);
    }
};

class Solution {
public:
    
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        DSU graph(n*n);
        
        vector <pair<int,pair<int,int>>> v;
        
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < n ; j++){
                pair <int,int> temp(i,j);
                v.push_back({grid[i][j],temp});
            }
        }
        sort(v.begin(),v.end());
        
        for( auto &edge : v ){
            int val = edge.first;
            int y = edge.second.first , x = edge.second.second;
            int node = n*y + x;
            for( auto &[dx,dy] : mover ){
                int i = y + dy , j = x + dx;
                if( i >= 0 and i < n and j >= 0 and j < n and grid[i][j] < grid[y][x] ){
                    int child = n*i + j;
                    graph.uunion(node,child);
                }
            }
            if( graph.isConnected() )
                return val;
        }
        
        return -1;
    }
};
class Solution {
public:
    
    struct dsu{
        
    private :
        vector <int> _parent;
        vector <int> _size;
    public : 
        
        dsu(int n ){
            _parent.resize(n,0);
            for( int i = 0 ; i < n ; i++)
                _parent[i] = i;
            _size.resize(n,0);
        }
        
        int ufind(int x){
            if( _parent[x] == x )
                return x;
            return _parent[x] = ufind(_parent[x]);
        }
        
        void uunion(int a ,int b){
            
            a = ufind(a), b = ufind(b);
            if( b > a )
                swap(a,b);
            
            _parent[b] = a;
            _size[a] += _size[b];
        } 
        
    };
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        dsu graph(n+1);
        vector <int> ans(2,0);
        for( auto &edge: edges ){
            int a = edge[0], b = edge[1];
            if( graph.ufind(a) == graph.ufind(b) ){
                ans[0] = a, ans[1] = b;
            }
            graph.uunion(a,b);
        }
        return ans;
    }
};
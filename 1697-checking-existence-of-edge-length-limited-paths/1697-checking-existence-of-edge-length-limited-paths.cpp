class Solution {
public:
    
    struct DSU {
    private : 
        vector <int> _parent, _size;
    public :
        
        DSU(int n){
            _parent.resize(n,1);
            for( int i = 0 ; i < n ; i++){
                _parent[i] = i;
            }
            _size.resize(n,1);
        }
        
        int ufind(int x){
            if( _parent[x] == x )
                return x;
            return _parent[x] = ufind(_parent[x]);
        }
        
        void uunion(int a,int b){
            
            a = ufind(a), b = ufind(b);
            if( a == b )
                return;
            if( a < b )
                swap(a,b);
            
            // a is greater
            _parent[b] = a;
            _size[a] += _size[b];
        }
        
    };
    
    static bool comparator(const vector <int> &a , const vector <int> &b){
        return a[2] < b[2];
    } 
    
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
          
        for( int i = 0 ; i < queries.size() ; i++ )
            queries[i].push_back(i);
        
        sort(queries.begin(),  queries.end(),  comparator);
        sort(edgeList.begin(), edgeList.end(), comparator);
        
        int q = queries.size();
        vector <bool> ans(q,false);
        
        int qdx = 0, edx = 0;
        DSU graph(n);
        
        while( qdx < q ){
            
            int limit = queries[qdx][2];
            while( edx < edgeList.size() and edgeList[edx][2] < limit )
                graph.uunion(edgeList[edx][0],edgeList[edx][1]), edx++;
            
            if( graph.ufind(queries[qdx][0]) == graph.ufind(queries[qdx][1]) ){
                int idx = queries[qdx][3];
                ans[idx] = true;
            }
                
            qdx++;
        }
        
        return ans;
    }
};
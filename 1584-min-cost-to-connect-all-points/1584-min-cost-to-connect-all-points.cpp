bool comparator(vector <int> &a, vector <int> &b){
    return a[2] < b[2];
}

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);        
    }

    
    
    struct dsu{
    private:
        vector <int> parent;
        vector <int> size; 
    public:
        
        dsu(int n){
            parent.resize(n,-1);
            size.resize(n,0);
        }
        
        void _make(int x){
            parent[x] = x;
            size[x] = 1;
        }
        
        int _find(int x){
            if( parent[x] == x) return x;
            return parent[x] = _find(parent[x]);
        }
        
        void _union(int a, int b){
            a = _find(a) , b = _find(b);
            if( size[a] < size[b] ) swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }  
        
    };
    
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector <vector <int>> edges;
        for( int i = 0 ; i < n ; i++){
            for( int j = i+1 ; j < n ; j++){
                edges.push_back({i,j,abs(points[i][0]-points[j][0])+
                                         abs(points[i][1]-points[j][1])});
            }
        }
        sort(edges.begin(), edges.end(), comparator);
        int e = 0, i = 0;
        int _sum = 0;
        dsu tree(n);
        for( int i = 0 ; i < n ; i++) tree._make(i);
        while( e < n-1 and i < edges.size()){
            int a = edges[i][0], b = edges[i][1], wt = edges[i][2];
            if( tree._find(a) == tree._find(b)) {
                i++;
                continue;
            }
            tree._union(a,b);
            _sum += wt;
        }
        return _sum;
        
    }
};
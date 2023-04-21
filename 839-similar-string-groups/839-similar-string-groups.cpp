struct DSU{
private:
    vector<int> _parent, _size;
public:
    DSU( int n ){
        _parent.resize(n,0);
        for( int i = 0 ; i < n ; i++)
            _parent[i] = i;
        _size.resize(n,1);
    }
    
    int ufind(int x){
        if( _parent[x] == x )
            return x;
        return _parent[x] = ufind(_parent[x]);
    }
    
    void uunion(int a, int b){
        
        a = ufind(a), b = ufind(b);
        if( a == b )
            return;
        if( a < b )
            swap(a,b);
        _parent[b] = a;
        _size[a] += b;
    }
    
    int getComps(){
        
        int ans = 0;
        for( int i = 0 ; i < _parent.size() ; i++){
            if( _parent[i] == i )
                ans++;
        }
        return ans;
    }
};

class Solution {
public:
    
    
    bool isSimilar(const string &s1, const string &s2){
        
        int dis =0;
        int n = s1.size();
        for( int i = 0 ; i < n ; i++){
            if( s1[i] != s2[i] )
                dis++;
            if( dis > 2 )
                return false;
        }
        return true;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();
        DSU graph(n);
        for( int i = 0 ; i < n ; i++){
            for( int j = i+1 ;j < n ; j++){
                if( isSimilar(strs[i],strs[j]))
                    graph.uunion(i,j);
            }
        }
        
        return graph.getComps();
    }
};
bool comparatorX( pair <vector <int> , int > &a, pair <vector <int> , int > &b ){
    return a.first[0] < b.first[0];
}
bool comparatorY(pair <vector <int> , int > &a,pair <vector <int> , int > &b){
    return a.first[1] < b.first[1];
}

class Solution {
public: 
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
        
        int maxSize(){
            return *max_element(_size.begin(),_size.end());
        }
        
        int gans(int n){
            int _ans = 0;
            for( int i = 0 ; i < n ; i++){
                if( parent[i] == i ) _ans += (_size[i]-1);
            }
            return _ans;
        }
        
    };
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        dsu graph(n);
        
        vector <pair <vector <int> , int >> stoneMap;
        for( int i = 0 ; i < n ; i++){
            stoneMap.push_back({stones[i],i});
        }     
        sort(stoneMap.begin(),stoneMap.end(), comparatorX);
        for( int i = 0 ; i < n-1 ; i++){
            if( stoneMap[i].first[0] == stoneMap[i+1].first[0]) 
                graph.uunion(stoneMap[i].second, stoneMap[i+1].second);
        }
        sort(stoneMap.begin(),stoneMap.end(), comparatorY);
        for( int i = 0 ; i < n-1 ; i++){
            if( stoneMap[i].first[1] == stoneMap[i+1].first[1]) 
                graph.uunion(stoneMap[i].second, stoneMap[i+1].second);
        }
        
        // graph.printDsu(n);
        
        return graph.gans(n);
        
    }
};
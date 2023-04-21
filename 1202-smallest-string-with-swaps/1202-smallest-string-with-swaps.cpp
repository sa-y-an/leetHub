class Solution {
public:
    
    struct dsu{
    private:
        vector <int> parent;
        vector <int> size;
    public :
        dsu (int n){
            parent.resize(n,-1);
            size.resize(n,0);
            for( int i = 0 ; i < n ; i++) parent[i] = i;
        }
        int _find(int x){
            if( parent[x] == x ) return x;
            return parent[x] = _find(parent[x]);
        }
        void _union(int a, int b){
            
            a = _find(a) , b = _find(b);
            if( size[a] < size[b]) swap(a,b);
            parent[b] = a;
            size[a] += b;
        }
        
    };
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {      
        
        int n =  s.size();
        dsu tree(n);
        for( auto &edge: pairs ) tree._union(edge[0],edge[1]);
        unordered_map <int, vector <int>> cc;
        
        for( int i = 0 ; i < n ; i++) cc[tree._find(i)].push_back(i);
        string ans = s;
        
        for( auto &it : cc ){
            string curr;
            auto & component = it.second;
            for( int x : component ) curr.push_back(s[x]);
            sort(curr.begin(), curr.end());
            int i = 0;
            for( int x : component) {
                ans[x] = curr[i];
                i++;
            }
        }
        
        return ans;
    }
};
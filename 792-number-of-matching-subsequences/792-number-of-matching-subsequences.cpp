class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int n = s.size();
        unordered_map <int,vector <int>> umap;
        for( int i = 0 ; i < n ; i++){
            umap[s[i]].push_back(i);
        }
        
        int ans = 0;
        for( auto &word : words ){
            bool flag = true;
            int last = -1;
            for( char ch : word ){
                if( umap.count(ch) == 0 ) {
                    flag = false;
                    break;
                }
                
                auto &v = umap[ch];
                int j = 0, k = v.size();
                for( ; j < k ; j++){
                    if(v[j] > last ){
                        last = v[j];
                        break;
                    }
                }
                
                if( j == v.size() ){
                    flag = false;
                    break;
                }
            }
            
            if( flag)
                ans++;
        }
        
        return ans;
    }
};
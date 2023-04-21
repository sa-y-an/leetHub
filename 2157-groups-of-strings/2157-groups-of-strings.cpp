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
        _size[a] += _size[b];
    }
    
    vector <int> getAns(){
        
        vector <int> ans = {0,1};
        for( int i = 0 ; i < _parent.size() ; i++){
            if( _parent[i] == i )
                ans[0]++;
        }
        ans[1] = *max_element(_size.begin(),_size.end());
        return ans;
    }
};


class Solution {
public:
    

    int getMask(string &s){
        int ans = 0;
        for( char ch : s ){
            int idx = ch-'a';
            ans |= (1<<idx);
        }  
        return ans;
    }
    
    vector<int> groupStrings(vector<string>& words) {
        
        int n = words.size();
        DSU graph(n);
        
        unordered_map <int,int> mpp,rep;
        
        for( int i = 0 ; i < n ; i++ ){
            
            int mask = getMask(words[i]);            
            if( mpp.count(mask) ){
                graph.uunion(mpp[mask],i);
            }
            
            for( int j = 0 ; j < 26 ; j++){
                
                if( ((mask>>j)&1) ){
                    
                    int del = mask;
                    del &= ~(1 << j);
                    
                    if( mpp.count(del) ) // deletion
                        graph.uunion(i,mpp[del]);
                    if( rep.count(del) ) // replace checking
                        graph.uunion(i,rep[del]);
                    rep[del] = i;
                }else{
                    int insert = mask | (1<<j); // insertion check
                    if(mpp.count(insert)) graph.uunion(mpp[insert],i);
                }
                
            }
            mpp[mask] = i;
        }
        
        return graph.getAns();
    }
};
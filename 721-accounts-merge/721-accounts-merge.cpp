class Solution {
    unordered_map <string,int> smap;
    unordered_map <int, string> opp;
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

    };
    
public:

    int generateSmap(vector<vector<string>>& accounts){
        int cnt = 0;
        for( auto &account : accounts ){
            int n = account.size();
            for( int i = 1 ; i < n ; i++){
                if( smap.count(account[i]) > 0 ) continue;
                smap[account[i]] = cnt;
                opp[cnt] = account[i];
                cnt++;
            }
        }
        
        return cnt;
    }
    
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int numEmails = generateSmap(accounts);
        dsu graph(numEmails);
        
        for( auto &account : accounts ){
            int m = account.size(), start = smap[account[1]]; 
            for( int i = 2; i < m ; i++){
                graph.uunion(start, smap[account[i]]);
            }
        }
        
        unordered_map <int, string > leader;
        unordered_map <int, vector <string>> collection;
        
        for( auto &arr : accounts ){
            int m = arr.size();
            for( int i = 1; i < m ; i++){
                int parent = graph.ufind(smap[arr[i]]);
                collection[parent].push_back(opp[smap[arr[i]]]);
                if( parent == smap[arr[i]]) leader[parent] = arr[0];
            }
            
        }

        vector <vector <string>> ans;
        
        for( auto &it : collection ){
            sort(it.second.begin(), it.second.end());
            vector <string> temp;
            temp.push_back(leader[it.first]);
            for( auto &str : it.second){
                if( !temp.empty() && temp.back() == str ) continue;
                temp.push_back(str);
            }
            ans.push_back(temp);
        }
        
        
        return ans;
        
    }
};
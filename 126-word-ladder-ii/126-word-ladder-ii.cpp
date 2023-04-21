const int INF = 1e6;
class Solution {
    vector <vector <int>> path;
    vector <int> level;
public:
    
    bool isEdge(const string &a , const string &b){
        
        int n = a.size();
        int ans = 0;
        for( int i = 0 ; i < n ; i++){
            if( a[i] != b[i])
                ans++;
        }
        return ans == 1;
    }
    
    
    void generate(vector <vector <int>> &parent, int node, vector <int> & curr){
                
        if( node == -1 ){
            path.push_back(curr);
            return;
        }
        
        for( auto par : parent[node] ){
            if( par != -1 and level[par] >= level[node])
                continue;
            curr.push_back(par);
            generate(parent,par,curr);
            curr.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        int n = wordList.size();
        if( find(wordList.begin(), wordList.end(), beginWord) != wordList.end() ){
            int idx = find(wordList.begin(), wordList.end(), beginWord) - wordList.begin();
            swap(wordList[n-1], wordList[idx]);
        }else{
            wordList.push_back(beginWord);
        }
        
        n = wordList.size();
        
        int target = -1, start = n-1;
        vector <vector <int>> adjList(n);
        
        for( int i = 0 ; i < n ; i++){
            if( wordList[i] == endWord ){
                target = i;
            }
            for( int j = i+1 ; j < n ; j++){
                if( isEdge(wordList[i], wordList[j]) ){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        if( target == -1 )
            return {};
        
        queue <int> q;
        q.push(start);
        
        vector <int> curr;
        vector <bool> visited(n,false);
        vector <vector <int>> parent(n);
        level.resize(n,INF);
        parent[start].push_back(-1);        
        level[start] = 1;
        
        
        while( !q.empty()){
            
            int node = q.front();
            q.pop();
            if( visited[node] )
                continue;
            visited[node] = true;
            bool flag = false;
            if( node == target )
                break;
            for( int child : adjList[node]){
                if( visited[child] )
                    continue;
                parent[child].push_back(node);
                q.push(child);
                level[child] = min(level[node] + 1, level[child]);
            }
        }
        
        for( auto &v: parent ){
            set <int> t(v.begin(),v.end());
            vector <int> f(t.begin(),t.end());
            v.clear();
            v = f;
        }

        curr.push_back(target);
        generate(parent,target,curr);
        vector<vector <string>> ans;
        
        for( auto &v : path){
            vector <string> temp;
            v.pop_back();
            reverse(v.begin(),v.end());
            for( int x : v ){
                temp.push_back(wordList[x]);
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};
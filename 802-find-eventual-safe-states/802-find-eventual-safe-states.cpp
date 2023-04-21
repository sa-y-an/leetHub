class Solution {
    unordered_set <int> terminals;
    vector <bool> visited;
public:
    
    bool dfs(vector<vector<int>>& graph, int source){

        if( visited[source] ) return false;
        visited[source] = true;
        
        for( auto child : graph[source] ){
            if( terminals.count(child) > 0 ) continue;
            if( not dfs(graph, child) ) return false;
        }
        
        terminals.insert(source);
        return true;
        
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        for( int i = 0 ; i < graph.size() ; i++)
            if( graph[i].size() == 0 ) terminals.insert(i);
        int n = graph.size();
        vector <int> ans;
        visited.resize(n,false);
        for( int i = 0 ; i < graph.size() ; i++){
            if( terminals.count(i) > 0 ) {
                ans.push_back(i);
                continue;
            }
            int cnt = 0;
            for( auto node : graph[i]){
                if( terminals.count(node) > 0 ) {
                    cnt++;
                    continue;
                }
                fill(visited.begin(), visited.end(), false);
                if( dfs(graph,node) ) cnt++;
                else break;
            }
            
            if( cnt == graph[i].size() ) ans.push_back(i);
        }
        
        return ans;
    }
};
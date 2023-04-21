class Solution {    
    vector <vector <int>> adjList;
    vector <bool> visited;
public:
    
    
    int dfs(int node){
        
        visited[node] = true;
        int ans = 1;
        for( int child : adjList[node]){
            if( visited[child] )
                continue;
            ans += dfs(child);
        }
        
        return ans;
    }
    
    
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        adjList.resize(n);
        visited.resize(n,false);
        
        for( auto node : restricted )
            visited[node] = true;
        
        for( auto &edge : edges ){
            
            if( visited[edge[0]] || visited[edge[1]] )
                continue;
            
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        return dfs(0);
    }
};
class Solution {
    vector <vector<int>> adjList;
    vector <int> low;
    vector <int> disc;
    vector <bool> visited;
    vector<vector<int>> ans;
    
    void reset(int n){
        ans.clear();

        adjList.clear();
        adjList.resize(n);

        low.clear();
        low.resize(n,-1);

        disc.clear();
        disc.resize(n,-1);

        visited.clear();
        visited.resize(n,false);
    }
    
public:
    

    void dfs(int ver, int par = -1 , int timer = 0){
        
        // visit a vertex and set its low and discovery times
        visited[ver] = true;
        disc[ver] = timer;
        low[ver] = timer;

        // 
        for( int child : adjList[ver]){
            // if the child is a parent continue
            if( visited[child] and child == par )
                continue;
            
            // else if child is not a parent but was visited before, 
            // this means this is a backedge 
            // hence we update its low to the discovery of the ver
            if( visited[child] )
                low[ver] = min(low[child], low[ver]);
            
            // if not visited do a dfs on the child
            else
                dfs(child, ver, timer+1);
            
            // backtracking steps 
            
            // we update the low of the ver to the low of its child
            // since any of its low might get updated due to a backedge 
            low[ver] = min(low[child], low[ver]);
            
            // if the low of the child > discovery time of the vertex 
            // it implies it has no backedge and it can only be reached 
            // via its parent
            
            if( low[child] > disc[ver] ){
                ans.push_back({ver,child});
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        reset(n);
        for( auto &edge : connections ){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        for( int i = 0 ; i < n ; i++){
            if( visited[i] )continue;
            dfs(i);
        }
        return ans;
    }
};
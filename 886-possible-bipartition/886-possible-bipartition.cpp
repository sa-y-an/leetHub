class Solution {
    vector <bool> visited;
    vector <int> depth;
public:
    
    bool ifOddLenCycle(vector<vector<int>>& adjList, int ver,int par){
        
        visited[ver] = true;
        bool ans = false;
        
        for( int child : adjList[ver]){
            if( child == par ) continue;
            else if( visited[child]  ){
                int dis = abs(depth[child]-depth[ver]);
                if( dis%2 == 0 )
                    ans |= true;
            }
            else{
                depth[child] = depth[ver] + 1;
                ans |= ifOddLenCycle(adjList,child,ver);
            } 
                
        }
        return ans;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        visited.resize(n,false);
        depth.resize(n,0);
        for( int i = 0 ; i < n ; i++){
            if( !visited[i] ){
                if(ifOddLenCycle(graph,i,-1))
                    return false;
            }
        }
        
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector <vector <int>> adjList(n);
        for( auto edge : dislikes ){
            int a = edge[0], b = edge[1];
            a--,b--;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        
        return isBipartite(adjList);
    }
};
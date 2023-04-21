class Solution {
    vector <int> ans;
    vector <vector <int>> adjList;
    vector <bool> visited;
public:

    void topSort(int x){

      visited[x] = true;
      for( int child : adjList[x]){
        if( visited[child] )
          continue;
        topSort(child);
      }
      ans.push_back(x);  
    }
    
    
    bool dfs(int x, unordered_set <int> &ancestors){

      visited[x] = true;
      bool res = false;
      for( int child : adjList[x]){
        if( ancestors.count(child) ){
            return true;
        }
        if( visited[child] )
          continue;
        ancestors.insert(x);
        res |= dfs(child,ancestors);
      }

      ancestors.erase(x);
      visited[x] = false;
      return res;
    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {

        adjList.resize(n);
        visited.resize(n,false);

        for( auto &edge : prerequisites ){
            int a = edge[0], b = edge[1];
            adjList[a].push_back(b);
        }

        bool res = false;
          for( int i = 0 ; i < n ; i++){
            if( !visited[i]){
              unordered_set <int> ancestors;
              if( dfs(i,ancestors) ) {
                return {};
                }
            }
          }

        visited.clear();
        visited.resize(n,false);
        for( int i = 0 ; i < n ; i++){
            if( !visited[i]){
              topSort(i);
            }
        }
        
        return ans;
    }
    
};
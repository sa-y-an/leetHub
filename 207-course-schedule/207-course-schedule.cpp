class Solution {
    vector <vector <int>> adjList;
    vector <int> visited;
public:
    
    bool dfs(unordered_set <int> &ancestors, int ver){
        
        if( visited[ver]) return false;
        if( ancestors.count(ver) > 0 ) return true;
        ancestors.insert(ver);
        
        for( int child : adjList[ver]){
            if( dfs(ancestors,child)) 
                return true;
        }
        
        ancestors.erase(ver);
        visited[ver] = true;
        return false;
        
    }
    
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // we cant take a course if there is a cyclic dependency
        int n = numCourses;
        adjList.resize(n);
        for( auto &edge : prerequisites ){
            adjList[edge[0]].push_back(edge[1]);
        }
        
        visited.resize(n,false);
        unordered_set <int> ancestors;
        
        for( int i = 0 ; i < n ; i++){
            if( !visited[i] )
                if( dfs(ancestors,i)) 
                    return false;
        }
        
        return true;
        
    }
};
class Solution {
public:
    
    int bfs(vector <vector <int>> &adjList, vector<int>& informTime, int root){
        
        queue <int> q;
        int n = informTime.size();
        vector <int> reachTime(n,0);
        q.push(root);
        while( !q.empty()){
            int ver = q.front();
            q.pop();
            for( int child : adjList[ver]){
                reachTime[child] = reachTime[ver] + informTime[ver]; 
                q.push(child);
            }
        }
        
        return *max_element(reachTime.begin(),reachTime.end());
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if( n == 1 ) return informTime[0];
        vector <vector <int>> adjList(n);
        int root = -1;
        for( int i = 0 ; i < n ; i++){
            int child = i, par = manager[i];
            if( par == -1 ) root = child;
            else {
                adjList[par].push_back(child);
            }
        }
        return bfs(adjList, informTime, root);
    }
};
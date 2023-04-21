// find the minimum time array
// from patience calculate last sent time : 
//      if ( p > m ) last_sent = 0
//      if( m%p == 0 )  last_sent = m/p-p 
//      else last_sent = m/p
// ans = max ( last_sent + 2*reach_time)

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        // bfs would do
        int n = patience.size();
        vector <vector <int>> adjList(n);
        vector <int> level(n, -1);
        vector <bool> visited(n,false);
        
        for( auto &edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        level[0] = 0;
        queue <int> q;
        q.push(0);
        visited[0] = true;
        
        while( not q.empty()){
            int curr = q.front();
            q.pop();
            
            for( auto child : adjList[curr]){
                if( visited[child]) continue;
                visited[child] = true;
                level[child] = level[curr]+1;
                q.push(child);
            }
        }
         
        vector <int> lastSent(n,0), ans(n,0);
        for( int i = 1 ; i < n ; i++){
            lastSent[i] = ((level[i]*2-1)/patience[i])*patience[i];
            ans[i] = lastSent[i] + 2*level[i];
        }       
        
        return *max_element(ans.begin(), ans.end())+1;
    }
};
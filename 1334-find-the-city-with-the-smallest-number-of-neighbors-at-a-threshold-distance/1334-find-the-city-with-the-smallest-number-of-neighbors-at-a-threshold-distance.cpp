const int INF = 1e9+7;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
            
        vector <vector <int>> distance(n, vector <int> (n,INF));
        
        for( auto &edge : edges ){
            distance[edge[0]][edge[1]] = edge[2];
            distance[edge[1]][edge[0]] = edge[2];
        }
        
        for( int k = 0 ; k < n ; k++){
            for( int i = 0 ;  i < n ; i++){
                for( int j = 0 ; j < n ; j++){
                    if( distance[i][k] != INF and distance[k][j] != INF )
                        distance[i][j] = min(distance[i][j],
                        distance[i][k] + distance[k][j]);
                }
            }
        }
        
        int _min = INT_MAX, _ans = -1;
        for( int i = 0 ; i < n ; i++){
            int _cnt = 0;
            for( int j = 0 ; j < n ; j++){
                // cout<<distance[i][j]<<" ";
                if(i ==j ) continue;
                if( distance[i][j] <= distanceThreshold ) _cnt++;
            }
            // cout<<"\n";
            if( _cnt <= _min ){
                _min = _cnt, _ans = i;
            }
        }
        
        return _ans;
    }
};
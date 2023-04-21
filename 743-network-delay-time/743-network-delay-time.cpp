const int INF = 1e9+7;

class Compare {
public :
    bool operator () (pair <int,int> &a, pair <int,int> &b){
        return a.second > b.second;
    }
};

class Solution {
    vector <int> distance;
    vector <bool> visited;
    vector <vector <pair <int, int>>> adjList;
public:
    
    void dijikstra(int source){
        
        distance[source] = 0;
        priority_queue < pair <int,int>, vector<pair<int,int>>  , Compare > pq;
        
        pq.push({source,0});
        
        while( not pq.empty()){
            
            auto curr = pq.top();
            int ver = curr.first, sourceDistance = curr.second;
            
            pq.pop();
            
            if( visited[ver]) continue;
            visited[ver] = true;

            for( auto &child : adjList[ver]){
                int childver = child.first, childwt = child.second;
                if( visited[childver]) continue;
                if( distance[childver] > distance[ver] + childwt ){
                    pq.push({childver, childwt+ sourceDistance});
                    distance[childver] = childwt + sourceDistance;
                }
            }
            
        }   
    }

    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        adjList.resize(n+1);
        for( int i = 0 ; i < times.size() ; i++){
            int source = times[i][0], dest = times[i][1], wt = times[i][2];
            adjList[source].push_back({dest,wt});
        }
        
        distance.resize(n+1,INF);
        visited.resize(n+1,false);
        
        dijikstra(k);
        distance[0] = -1;
        int _max = *max_element(distance.begin(), distance.end());
        if( _max == INF ) return -1;
        return _max;
        
    }
};
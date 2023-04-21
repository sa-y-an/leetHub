class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector <unordered_set <int>> adjList(n);
        for( int i = 0 ; i < roads.size() ; i++) {
            int a = roads[i][0] , b = roads[i][1];
            adjList[a].insert(b);
            adjList[b].insert(a);
        }

        int ans = 0;
        for( int i = 0 ; i < n ; i++) {
            for( int j = i+1 ; j < n ; j++) {
                int curr = adjList[i].size() + adjList[j].size();
                if( adjList[i].count(j)) {
                    curr--;
                }
                ans = max(ans,curr);
            }
        }

        return ans;
    }
};
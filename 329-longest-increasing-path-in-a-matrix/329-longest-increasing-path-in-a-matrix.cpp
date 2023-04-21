vector <pair <int,int>> dz = {{1,0},{0,1},{-1,0},{0,-1}};
class Solution {
    vector <vector <int>> dp;
public:
    
    int dfs(vector<vector<int>>& matrix, int y, int x){
        int n = matrix.size() , m = matrix[0].size();
        if( dp[y][x] != -1 ) return dp[y][x];
        int ans = 1;
        for( auto &[dy,dx] : dz ){
            int j = x + dx, i = y+dy;
            if( i < 0 or j < 0 or i >= n or j >= m or matrix[i][j] <= matrix[y][x]) continue;
            int pathSum = 1 + dfs(matrix,i,j);
            ans = max(ans, pathSum);
        }
        return dp[y][x] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        dp.resize(n, vector<int> (m, -1));
        
        int ans = 0;
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ;  j++){
                if( dp[i][j] == -1 ) ans = max(ans,dfs(matrix,i,j));
            }
        }
        
        return ans;
    }
};
const int mod = 1e9+7;
const vector <pair <int,int>> dz = {{1,0},{0,1},{0,-1},{-1,0}};
class Solution {
    int m,n;
    vector <vector<vector<int>>> dp;
public:
    
    int dfs(int y, int x, int k){
                
        if( y < 0 || x < 0 || y >= n || x >= m )
            return 1;
        
        if( dp[y][x][k] != -1 )
            return dp[y][x][k];
        if( k == 0 )
            return 0;
        
        int ans = 0;
        
        for( auto &[dy,dx] : dz ){
            int i = y + dy , j = x + dx;
            ans = (ans%mod + dfs(i,j,k-1)%mod)%mod;
        }
        
        return dp[y][x][k] = ans;
    }
    
    int findPaths(int N, int M, int maxMove, int startRow, int startColumn) {
        
        n = N, m = M;
        dp.resize(n, vector<vector<int>> (m,vector <int> (maxMove+1,-1)));
        return dfs(startRow,startColumn,maxMove);
        
    }
};
/*

- chose the min cost path
- Return 0 if the current cost > 0 

int findMaxNeg(vector<vector<int>>& dungeon, int i = 0 , int j = 0 ){
    int n = dungeon.size() , m = dungeon[0].size();
    if( i == n-1 and j == m-1 ) return dungeon[i][j] > 0 ? 0 : dungeon[i][j];
    if( i >= n or i < 0 or j >= m or j < 0 ) return INF;
    if( dp[i][j] != -1 ) return dp[i][j];
    int addon = max(findMaxNeg(dungeon, i+1, j), findMaxNeg(dungeon, i, j+1));
    if( addon + dungeon[i][j] > 0 ) return dp[i][j] = 0;
    else return dp[i][j] = dungeon[i][j]+ addon;
}

*/
const int INF = -1e4-5;
class Solution {
public:
      
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size() , m = dungeon[0].size();
        vector <vector <int>> dp(n , vector <int> (m,0) );
        dp[n-1][m-1] = dungeon[n-1][m-1] > 0 ? 0 : dungeon[n-1][m-1];
        for( int i = n-1 ; i >= 0 ; i--){
            for( int j = m-1 ; j >= 0 ; j--){
                if( i == n-1 and j == m-1) continue;
                int addon = INF;
                if( i+1 < n ) addon = max(addon,dp[i+1][j]);
                if( j+1 < m ) addon = max(addon,dp[i][j+1]);
                if( addon + dungeon[i][j] > 0 ) dp[i][j] = 0;
                else dp[i][j] = dungeon[i][j] + addon;
            }
        }
        
        return -1*dp[0][0] + 1;
    }
};
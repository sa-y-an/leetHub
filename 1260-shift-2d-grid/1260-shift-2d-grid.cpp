class Solution {
public:
    
    void shift(vector<vector<int>>& grid, vector<vector<int>>& ans){
        int n = grid.size(), m = grid[0].size();
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){                
                if( j == m-1 ) {
                    if( i == n-1 ) ans[0][0] = grid[n-1][m-1];
                    else ans[i+1][0] = grid[i][m-1];
                }
                else ans[i][j+1] = grid[i][j];
            }
        }
        
        grid = ans;
    }
    
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector <vector <int>> ans  = grid;
        
        // k = k % lcm(m,n);        
        for( int i = 0 ; i < k ; i++) shift(grid, ans);
        return ans;
        
    }
};
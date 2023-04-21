class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        for( int i = 0 ; i < n ; i++){
            int j = m-1;
            while( j >= 0 and grid[i][j] < 0 ) cnt++,j--;
        }
        return cnt;
    }
};
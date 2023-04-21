class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size();
        vector <int> prev(m,0);
        
        int ans = 0;
        
        for( int j = 0 ; j < m ; j++){
            prev[j] = matrix[0][j]-'0';
            ans = max(ans, prev[j]);
        }
        
        for( int i = 1 ; i < n ; i++){
            vector <int> curr(m,0);
            curr[0] = matrix[i][0]-'0';
            ans = max(ans, curr[0]);
            for( int j = 1; j < m ; j++){
                if( matrix[i][j] == '1' ){
                    curr[j] = min({prev[j],prev[j-1],curr[j-1]}) + 1;
                    ans = max(curr[j],ans);
                }
            }
            prev = curr;
        }
        
        return ans*ans;
    }
};
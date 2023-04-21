class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector <vector <int>> ans;
        vector <int> prev(1,1);
        ans.push_back(prev);
        if( n == 1 )
            return ans;
        for( int i = 1 ; i < n ; i++){
            vector <int> curr(i+1,1);
            for( int j = 1; j < i ; j++){
                curr[j] = ans[i-1][j] + ans[i-1][j-1];
            }
            ans.push_back(curr);
        }
        
        return ans;
    }
};
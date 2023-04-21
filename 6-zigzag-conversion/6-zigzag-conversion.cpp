class Solution {
public:
    string convert(string s, int numRows) {
        
        int n = s.size(), idx = 0;
        vector <vector <char>> grid(numRows);
        
        while( idx < n ){
            
            for( int i = 0 ; i < numRows and idx < n ; i++){
                grid[i].push_back(s[idx]);
                idx++;
            }
            
            for( int i = numRows-2 ; i > 0 and idx < n  ; i--){
                grid[i].push_back(s[idx]);
                idx++;
            }
            
        }
        
        string ans;
        
        for( int i = 0 ; i < numRows ; i++){
            for( int j = 0 ; j < grid[i].size() ; j++){
                ans.push_back(grid[i][j]);
            }
        }
        
        return ans;
    }
};
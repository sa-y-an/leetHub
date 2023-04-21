class NumMatrix {
    vector <vector <int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        prefix.resize(n, vector <int> (m, 0));
        for( int i = 0 ; i < n ; i++){
            prefix[i][0] = matrix[i][0];
            for( int j = 1 ; j < m ; j++){
                prefix[i][j] = matrix[i][j] + prefix[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int s = 0;
        
        for( int i = row1 ; i <= row2 ; i++){
            if( col1 != 0 )
                s += prefix[i][col2] - prefix[i][col1-1];
            else 
                s += prefix[i][col2];
        }
        return s;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
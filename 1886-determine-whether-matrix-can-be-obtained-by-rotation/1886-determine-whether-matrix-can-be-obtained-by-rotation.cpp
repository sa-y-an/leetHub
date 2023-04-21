class Solution {
public:
    
    void rotateClockWise(vector<vector <int>> &mat){
        reverse(mat.begin(),mat.end());
        int n = mat.size();
        for( int i = 0 ; i < n ; i++){
            for( int j = i+1 ; j < n ; j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        int k = 3;
        if( mat == target )
            return true;
        while( k--){
            rotateClockWise(mat);
            if( mat == target )
                return true;
        }
        
        return false;
    }
};
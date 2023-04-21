class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int m = mat[0].size() , n = mat.size();
        int x = 0;
        
        while( x < m ){
            vector <int> temp;
            int i = 0, j = x;
            while( i < n and j < m ){
                temp.push_back(mat[i][j]);
                i++, j++;
            }
            sort(temp.begin(), temp.end());
            i = 0, j = x;
            int k = 0;
            while( i < n and j < m ){
                mat[i][j] = temp[k];
                i++,j++, k++;
            }
            x++;
        }
        
        int y = 1;
        while( y < n ){
            vector <int> temp;
            int i = y, j = 0;
            while( i < n and j < m ){
                temp.push_back(mat[i][j]);
                i++, j++;
            }
            sort(temp.begin(), temp.end());
            i = y, j = 0;
            int k = 0;
            while( i < n and j < m ){
                mat[i][j] = temp[k];
                i++,j++, k++;
            }
            y++;
        }
        
        return mat;
    }
};
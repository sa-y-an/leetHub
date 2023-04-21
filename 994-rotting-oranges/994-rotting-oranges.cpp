vector <pair<int, int>> mover = {{1,0},{0,1},{-1,0},{0,-1}};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& matrix) {

        int n = matrix.size() , m = matrix[0].size();
        queue <pair<int,int>> q; // {y,x}
        vector <int> level(m*n,0); // 

        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                if( matrix[i][j] == 2 ){
                    q.push({i,j});
                    level[j+m*i] = 0; // x + n*y
                }
            }
        }

        while( not q.empty()){

            auto curr = q.front();
            int parx = curr.second, pary = curr.first;
            q.pop();

            for( auto move : mover ){
                int childx = parx + move.first, childy = pary +move.second;
                if( childx >= m || childy >= n || childx < 0 || childy < 0 || matrix[childy][childx] != 1 ) continue;
                matrix[childy][childx] = 2;
                level[childx+ m*childy] = level[parx + m*pary] + 1;
                q.push({childy,childx});
            }
        }


        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                if(matrix[i][j] == 1 ) return -1;
            }
        }

      return *max_element(level.begin(), level.end());
        
        
    }
};
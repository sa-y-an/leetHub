vector <pair <int, int>> mover = {{-1,-1},{1,1},{1,0},{0,1},{-1,0},{0,-1},{-1,1},{1,-1}};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int n = board.size(), m = board[0].size();
        vector <vector <int>> next(n , vector <int> (m,0));
        
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                
                int live = 0;
                for( auto move : mover ){
                    
                    int _i = i + move.first;
                    int _j = j + move.second;
                    
                    if( _i < 0 or _i >= n or _j < 0 or _j >= m ) continue;
                    
                    live += board[_i][_j];
                }
                
                if( board[i][j] == 1 ){
                    if( live < 2 ) next[i][j] = 0;
                    else if( live == 2 or live == 3 ) next[i][j] = 1;
                    else next[i][j] = 0;
                }
                else {
                    if( live == 3 ) next[i][j] = 1;
                }
                
            }
        }
        
        board.clear();
        board = next;
    }
};


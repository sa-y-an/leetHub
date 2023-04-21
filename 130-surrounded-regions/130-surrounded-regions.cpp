vector <pair <int,int>> dz = {{1,0},{-1,0},{0,1},{0,-1}};
class Solution {
public:
    
    void color(vector<vector<char>> &board, int y,int x,char toColor, char c){
        
        int n = board.size() , m = board[0].size();
        board[y][x] = c;
        
        for( auto &[dx,dy] : dz ){
            int i = dy+y , j = dx + x;
            if( i < n and i >= 0 and j < m and j >= 0 and board[i][j] == toColor )
                color(board,i,j,toColor,c);
        }
        
    }
    
    void solve(vector<vector<char>>& board) {
        
        
        int n = board.size() , m = board[0].size();
        for( int y = 0 ; y < n ; y++){
            if( board[y][0] == 'O' ) 
                color(board,y,0,'O','P');
            if( board[y][m-1] == 'O')
                color(board,y,m-1,'O','P');
        }
        
        for( int x = 1 ; x < m-1 ; x++){
            if( board[0][x] == 'O')
                color(board,0,x,'O','P');
            if( board[n-1][x] == 'O')
                color(board,n-1,x,'O','P');
        }    
        
        for( int i = 1 ; i < n-1 ; i++){
            for( int j = 1 ; j < m-1 ; j++){
                if( board[i][j] == 'O' )
                    color(board,i,j,'O','X');
            }
        }
        
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                if( board[i][j] == 'P')
                    color(board,i,j,'P','O');
            }
        }
        
    }
};
class Solution {
public:
    
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        int dfsCount = 0;
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                if( board[i][j] == 'X'){
                    if( i+1 < n and board[i+1][j] == 'X') {
                        int y = i;
                        while(y < n and board[y][j] == 'X') board[y++][j] = 'Y';
                    }
                    else {
                        int x = j;
                        while( x < m and board[i][x] == 'X') board[i][x++] = 'Y';
                    }
                    dfsCount++;
                }
            }
        }
        return dfsCount;
    }
};
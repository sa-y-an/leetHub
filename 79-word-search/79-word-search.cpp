vector <pair<int,int>> dz = {{1,0},{0,1},{-1,0},{0,-1}};

class Solution {
    vector <vector <bool>> visited;
public:
    
    bool isPresent(vector<vector<char>> &board, string &word,int idx, int y, int x){
        
        int n = board.size(), m = board[0].size();
        
        if( idx == word.size())
            return true;
        
        if( y < 0 || y >= n || x < 0 || x >= m || visited[y][x] )
            return false;
        bool ans = false;
        visited[y][x] = true;
        
        if( board[y][x] == word[idx] ){
            for( auto &[dy,dx] : dz ){
                int i = y + dy , j = x + dx;
                ans |= isPresent(board,word,idx+1,i,j);
            }    
        }
        
        visited[y][x] = false;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size() , m = board[0].size();
        visited.resize(n , vector <bool> (m,false));
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                if( board[i][j] == word[0] and isPresent(board,word,0,i,j))
                    return true;
            }
        }
        
        return false;
    }
};
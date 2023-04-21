class Solution {
    
    vector <pair<int,int>> prev;
    vector<vector<string>> ans;
    int n;
public:
    
    bool canPlace(int y, int x){
        for( auto &[py,px] : prev ){
            if( y == py)
                return false;
            if( y+x == py + px )
                return false;
            if( y-x == py - px )
                return false;
        }
        return true;
    }
    
    
    void dfs( vector <string> &pos, int X){
        
        if( X == n ){
            ans.push_back(pos);
            return;
        }
        
        for( int y = 0 ; y < n ; y++){
            if( !canPlace(y,X) )
                continue;

            // place
            pos[y][X] = 'Q';
            prev.push_back({y,X});
            dfs(pos,X+1);
            
            // backtracking
            // uplace
            
            pos[y][X] = '.';
            prev.pop_back();
            
        }
        
    }
    
    vector<vector<string>> solveNQueens(int N) {
        
        n = N;
        vector <string> pos(n, string(n,'.'));
        dfs(pos,0);
        return ans;
    }
};
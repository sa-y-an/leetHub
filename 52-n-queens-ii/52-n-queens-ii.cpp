class Solution {
    vector <pair<int,int>> prev;
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
    
    int dfs( int X){
        
        if( X == n ){
            return 1;
        }
        
        int ans = 0;
        for( int y = 0 ; y < n ; y++){
            if( !canPlace(y,X) )
                continue;

            // place
            prev.push_back({y,X});
            ans += dfs(X+1);
            
            // backtracking
            // uplace
            
            prev.pop_back();        
        }
        
        return ans;
    }
    
    
    int totalNQueens(int N) {
        n = N;
        return dfs(0);
    }
};
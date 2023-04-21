class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    
        vector <vector <int>> ans(n , vector <int> (n,0));
        int start = 0, endx = n-1, endy = n-1, num =1 ;
        
        while( start <= endx and start <= endy and num <= n*n ){
            for( int i = start ; i <= endx ; i++) ans[start][i] = num++;
            for( int y = start+1 ; y <= endy ; y++) ans[y][endx] =  num++;
            for( int x = endx-1 ; x >= start ; x--) ans[endy][x] = num++;
            for( int y = endy-1 ; y > start ; y--) ans[y][start] = num++; 
            start++, endx--, endy--;
        }
        
        return ans;
    }
};
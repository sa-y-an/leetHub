const int INF = 1e5;
class Solution {
    vector <vector <vector <int>>> dp;
public:
    
    int fill(int c,int h, int w){
        
        if( c == 0 and h == 0 and w == 0 )
            return 0;
        int ans = INF;
        
        if( dp[c][h][w] != -1 )
            return dp[c][h][w];
        
        if( c > 0 and h > 0 )
            ans = min(ans,1 + fill(c-1,h-1,w));
        if( h > 0 and w > 0 )
            ans = min(ans, 1 + fill(c,h-1,w-1));
        if( c > 0 and w > 0 )
            ans = min(ans, 1 + fill(c-1,h,w-1));
            
        
        if( ans == INF ){
            if( c > 0 )
                ans = min(ans, 1 + fill(c-1,h,w));
            if( h > 0 )
                ans = min(ans, 1 + fill(c,h-1,w));   
            if( w > 0 )
                ans = min(ans, 1 + fill(c,h,w-1));
        }
        return dp[c][h][w] = ans;
        
    }
    
    int fillCups(vector<int>& amount) {
        int c = amount[0], h = amount[1] , w = amount[2];
        dp.resize(c+1, vector <vector <int>> (h+1, vector <int> (w+1,-1)));
        return fill(c,h,w);
    }
};
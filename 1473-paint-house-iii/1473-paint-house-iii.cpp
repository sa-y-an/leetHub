const int INF = 1e8;
class Solution {
    vector <vector<vector <int>>> dp;
public:
    
    int minPrice(vector <int> &houses, vector<vector<int>>& cost, int idx, int prev, int k){
        
        if( idx < 0 and k > 0 ){
            return INF;
        }
        
        if( k == 0 and idx < 0 )
            return 0;
        
        if( dp[idx][prev][k] != -1 )
            return dp[idx][prev][k];
        
        // if no more segments left
        if( k == 0 ){ // 
            
            int numH = 0;
            int price = 0;
            int ccnt = 0;
            int pcnt = 0;
            for( int i = 0 ; i <= idx ; i++){
                if( houses[i] > 0 )
                    ccnt++;
                if( houses[i] == prev )
                    pcnt++;
                price += cost[i][prev-1];
            }
            
            if( pcnt == idx+1)
                return dp[idx][prev][k] = 0;
            else if( ccnt > 0 )
                return dp[idx][prev][k] = INF;
            
            return dp[idx][prev][k] = price;
        }
        
        // leave untouched
        int n = houses.size();
        
        // already colored houses
        if( houses[idx] != 0 ){
            int newK = k;
            if( houses[idx] != prev ) // if new segment
                newK--;
            return dp[idx][prev][k] = minPrice(houses,cost,idx-1,houses[idx], newK);
        }
        
        
        int notColor = INF , color = INF;
        int ans = INF;
        
        // color prev 
        if( prev != 0 ){
            color = cost[idx][prev-1] + minPrice(houses, cost, idx-1,prev, k);
            ans = min(color, ans);
        }
        
        // new color
        for( int col = 0 ; col < cost[idx].size() ; col++ ){
            int newColor = col+1;
            if( newColor != prev ){
                notColor = cost[idx][col] + minPrice(houses, cost, idx-1, newColor,k-1);
                ans = min(ans, notColor);
            }
        }
        
        return dp[idx][prev][k] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        dp.resize(m+1, vector <vector <int>> (n+1, vector <int> (target+1,-1)));
        int ans = minPrice(houses, cost, m-1,0, target);
        if( ans >= INF )
            return -1;
        return ans;
    }
};
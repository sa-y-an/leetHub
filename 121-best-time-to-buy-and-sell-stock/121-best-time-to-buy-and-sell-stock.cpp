const int INF = 1e5+10;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), minSoFar = INF, ans = 0;
        for( int i = 0 ; i < n ; i++){
            ans = max(ans, prices[i]-minSoFar);
            minSoFar = min(minSoFar, prices[i]);
        }
        return ans;
    }
};
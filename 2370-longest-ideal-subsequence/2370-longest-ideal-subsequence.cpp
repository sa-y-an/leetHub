class Solution {
public:
    int longestIdealString(string s, int k) {
        
        vector <int> dp(26,0);
        for( char ch : s ){
            int curr = ch-'a';
            int maxi = 0;
            for( int i = max(curr-k,0) ; i <= min(curr+k,25); i++){
                maxi = max(maxi, dp[i]);
            }
            dp[curr] = 1 + maxi;
        }
        
        return *max_element(dp.begin(),dp.end());
    }
};
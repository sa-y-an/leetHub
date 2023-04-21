class Solution {
    unordered_map <int,int> dp;
public:
    int climb(int n){
        if( n < 0 ) return 0;
        if( n <= 1 ) return 1;
        if( dp.count(n) > 0 ) return dp[n];
        return dp[n] = climb(n-1) + climb(n-2);
    }
    
    int climbStairs(int n) {
        return climb(n);
    }
};
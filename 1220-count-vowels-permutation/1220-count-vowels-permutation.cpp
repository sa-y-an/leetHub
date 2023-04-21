const int m = 1e9+7;
class Solution {
    vector <vector <int>> allowed;
    vector <vector <int>> dp;
public:
    
    int numWays(int idx,int prev, const int &n){
        
        if( idx == n )
            return 1;
        
        if( dp[idx][prev] != -1 )
            return dp[idx][prev];
        
        vector <int> &curr = allowed[prev];
        int ans = 0;
        for( int x : curr ){
            ans = (ans%m + numWays(idx+1,x,n)%m)%m;
        }
        
        return dp[idx][prev] = ans;
    }
    
    int countVowelPermutation(int n) {
        
        allowed.resize(6);
        allowed[0] = {1};
        allowed[1] = {0,2};
        allowed[2] = {0,1,3,4};
        allowed[3] = {2,4};
        allowed[4] = {0};
        allowed[5] = {0,1,2,3,4};
        
        dp.resize(n+1, vector <int> (6,-1));
        return numWays(0,5,n);
    }
};
class Solution {
    long long longestLen;
    vector <vector <int>> dp;
public:

    int longestSubsequence(string s, int k) {
        longestLen = k;
        int n = s.size();
        dp.assign(n+1, vector <int> (n+1,-1));
        return maxPoints(s,n, 0, 0);
    }

    int maxPoints( string &str, int i, int j, long long sum ){
        
        if( sum > longestLen )
            return 0;
        
        if( i < 0 )
            return 0;
        
        if( dp[i][j] != -1 )
            return dp[i][j];
        
        int take = 0 , notTake = 0;
        if( str[i] == '0' ){
            take = 1 + maxPoints(str,i-1, j+1 , sum);
        }
        else if( str[i] == '1' && j < 32){
            long currSum = pow(2, j) + sum;
            if( currSum <= longestLen ){
                take = 1 + maxPoints(str, i-1, j+1, currSum);
            }
        }
        
        notTake = maxPoints(str,i-1,j,sum);
        return dp[i][j] = max(take, notTake);
    }

};
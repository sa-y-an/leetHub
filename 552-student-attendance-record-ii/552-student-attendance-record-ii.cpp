const int m = 1e9+7;
const int N = 1e5+7;
int dp[N][2][2][2];
class Solution {
    int N;
public:
    
    int countWays(int idx, bool isLate1, bool isLate2, int absent){
        
        if( idx == N )
            return 1;
        if( absent < 0 )
            return 0;
        if( dp[idx][isLate1][isLate2][absent] != -1 )
            return dp[idx][isLate1][isLate2][absent];
        
        // present 
        int present = countWays(idx+1,false,isLate1,absent)%m;
        
        int notPresent = 0;
        if( absent > 0 ){
            notPresent = countWays(idx+1,false,isLate1,absent-1)%m;
        }
        
        int late = 0;
        if( !(isLate1 and isLate2) ){
            late = countWays(idx+1,true,isLate1,absent)%m;
        }
        
        return dp[idx][isLate1][isLate2][absent] = (late%m + (present%m + notPresent%m)%m )%m;
    }
    
    int checkRecord(int n) {
        N = n;
        memset(dp, -1, sizeof(dp));
        return countWays(0,false,false,1);
    }
};
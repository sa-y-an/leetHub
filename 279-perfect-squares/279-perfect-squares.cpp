const int INF = 1e5;
class Solution {
    vector <int> nums;
    vector <vector<int>> dp;
public:
    
    int numdigits(int target, int idx){
        
        if( target == 0 ) return 0;
        if( target < 0 ) return INF;
        if( idx < 0 ) return INF;
        if( dp[idx][target] != -1 ) return dp[idx][target];
            
        int take = 1 + numdigits(target-nums[idx], idx);
        int not_take = numdigits(target,idx-1);
        
        return dp[idx][target] = min(take,not_take);   
    }
    
    
    int numSquares(int n) {
        int x = sqrt(n);
        for( int i = 1 ; i <=x ; i++ ) nums.push_back(i*i);
        int m = nums.size();
        
        dp.resize(m, vector<int> (n+1,-1));
        return numdigits(n,nums.size()-1);
    }
};
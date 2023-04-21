class Solution {
    vector <vector <vector <int>>> dp;
public:
    
    int maxScore(vector<int>& nums, int l, int r, int can1 ){
        
        if( l > r )
            return 0;
        
        if( dp[l][r][can1] != -1 )
            return dp[l][r][can1];
        
        if( can1 ){
            int left = nums[l] + maxScore(nums,l+1,r, 0);
            int right = nums[r] + maxScore(nums,l,r-1,0);
            
            return dp[l][r][can1] = max(left,right);
        }
        else {
            int left = maxScore(nums,l+1,r, 1);
            int right = maxScore(nums,l,r-1,1);
            return dp[l][r][can1] = min(left,right);
        }
        
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if( n%2 == 0 )
            return true;
        
        
        dp.resize(n, vector<vector<int>> (n, vector <int> (2,-1)));
        
        int player1 = maxScore(nums,0,n-1, 1);
        int total = accumulate(nums.begin(), nums.end(),0);
        int player2 = total-player1;
        return player1 >= player2;
    }
};
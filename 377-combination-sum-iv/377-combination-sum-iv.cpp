class Solution {
    vector <int> dp;
public:
    
    int numWays(vector <int> &nums, int target ){
        
        if( target == 0 )
            return 1;
        if( dp[target] != -1 )
            return dp[target];
        int n = nums.size();
        int ans = 0;
        for( int i = 0 ; i < n ; i++ ){
            if( target - nums[i] >= 0 )
                ans += numWays(nums, target-nums[i]);
        }
        
        return dp[target] = ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        dp.resize(target+1, -1);
        return numWays(nums, target);
    }
};
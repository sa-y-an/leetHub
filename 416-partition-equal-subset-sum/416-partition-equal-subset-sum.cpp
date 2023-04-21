class Solution {
    vector <vector <int>> dp;
public:
    
    bool subSetSum(vector <int> &nums, int target, int idx = 0){
        if( idx >= nums.size() or target < 0 ) return false;
        if( target == 0 ) return true;
        if( dp[idx][target] != -1 ) return dp[idx][target];
        
        return dp[idx][target] = 
            (subSetSum(nums, target-nums[idx], idx+1) or subSetSum(nums, target, idx+1));
    }
    
    bool canPartition(vector<int>& nums) {
        int s = accumulate( nums.begin() , nums.end(), 0);
        if( s%2 != 0 ) return false;
        dp.resize(nums.size(), vector <int> (s+1, -1));
        return subSetSum(nums, s/2);
    }
};
class Solution {
    vector <int> dp;
public:
    
    bool isValid(vector <int> &nums, int idx ){
        
        int n = nums.size();
        if( idx == n )
            return true;
        
        if( dp[idx] != -1 )
            return dp[idx];
        
        bool ans = false;
        if( idx+1 < n and nums[idx] == nums[idx+1] )
            ans |= isValid(nums, idx+2);
        if( idx+2 < n and nums[idx] == nums[idx+1] and nums[idx+1] == nums[idx+2] )
            ans |= isValid(nums,idx+3);
        if( idx+2 < n and nums[idx+1] - nums[idx] == 1 and nums[idx+2] - nums[idx+1] == 1)
            ans |= isValid(nums,idx+3);
        
        return dp[idx] = ans;
    }
    
    bool validPartition(vector<int>& nums) {
        
        int n = nums.size();
        dp.resize(n+1,-1);
        return isValid(nums,0);
    }
};
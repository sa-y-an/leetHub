class Solution {
    vector <int> dp, dp1;
public:
    
    int maxProfit1(vector <int> & nums, int idx = 0){
        int n = nums.size();
        if( idx >= n-1 ) return 0;
        if( dp[idx] != -1 ) return dp[idx];
        int ans = nums[idx];
        ans += max( maxProfit1(nums,idx+2) , maxProfit1(nums,idx+3) );
        return dp[idx] = ans;
    }
    int maxProfit2(vector <int> & nums, int idx = 1){
        int n = nums.size();
        if( idx >= n ) return 0;
        if( dp1[idx] != -1 ) return dp1[idx];
        int ans = nums[idx];
        ans += max( maxProfit2(nums,idx+2) , maxProfit2(nums,idx+3) );
        return dp1[idx] = ans;
    }

    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        dp1.resize(nums.size(),-1);
        if ( nums.size() == 1 ) return nums[0];
        if(nums.size() >= 3 ) return max({maxProfit1(nums),maxProfit2(nums,2), maxProfit2(nums),nums[2]});
        return max(maxProfit1(nums), maxProfit2(nums));       
    }
};
class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        dp[n-1] = 1;
        
        for( int i = n-2 ; i >= 0 ; i--){
            int ans = 0;
            for( int j = n-1 ; j > i ; j--){
                if( nums[j]%nums[i] == 0 )
                    ans = max( ans, dp[j]);
            }
            dp[i] = ans+1;
        }
        
        int idx = max_element(dp, dp+n) - dp;
        vector <int> ans;
        
        while( dp[idx] > 1 ){
            ans.push_back(nums[idx]);
            int i = idx+1;
            while( nums[i]%nums[idx] != 0 or 1+dp[i] != dp[idx]) i++;
            idx = i;
        }
        ans.push_back(nums[idx]);
        return ans;
    }
};
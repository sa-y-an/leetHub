class Solution {
    vector <vector <int>> dp;
public:
    
    int maxPoints(vector <int> &nums, int l, int r){
        
        if( l > r)
            return 0;
        
        if( dp[l][r] != -1 )
            return dp[l][r];
        
        for( int i = l ; i <= r ; i++ ){
            dp[l][r] = max(dp[l][r], 
                           nums[l-1]*nums[i]*nums[r+1] + 
                           maxPoints(nums, l, i-1) + maxPoints(nums, i+1, r));
        }
        
        return dp[l][r];
    }
    
    
    int maxCoins(vector<int>& nums) {
        
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n = nums.size();
        dp.resize(n, vector <int> (n, -1));
        return maxPoints(nums, 1, n-2);
    }
};
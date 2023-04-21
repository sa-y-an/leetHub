class Solution {
    vector <vector <int>> dp;
public:
    
    int longestLen(vector <int> &nums, int idx, int prev, int wiggle){
        
        int n = nums.size();
        if( idx == n )
            return 0;
        if( dp[idx][prev] != -1 )
            return dp[idx][prev];
        
        int take = 0, diff = 1;
        if( prev != n )
            diff = nums[idx]-nums[prev];
        
        if( (diff*wiggle < 0 || wiggle == 2) and diff != 0 ){
            
            int newWigle = 0;
            if( diff != 0 )
                newWigle = diff/abs(diff);
            if( prev == n )
                newWigle = 2;
            
            take = 1 + longestLen(nums,idx+1,idx, newWigle);
        }
        int notTake = longestLen(nums,idx+1,prev,wiggle);
        return dp[idx][prev] = max(take,notTake);
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1, vector <int> (n+1,-1));
        int ans = longestLen(nums,0,nums.size(),2);
        return ans;
    }
};
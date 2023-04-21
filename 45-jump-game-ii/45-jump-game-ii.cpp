const int INF = 1e9;
class Solution {
    vector <int> dp;
public:
    
    
    int minJump(vector <int> &nums, int idx){
        
        int n = nums.size();
        if( idx >= n ) return INF;
        if( dp[idx] != -1 ) return dp[idx];
        if( idx == n-1 ) return dp[idx] = 0;
        
        int maxJump = nums[idx];
        int ans = INF;
        for( int i = 1; i <= maxJump ; i++){
            ans = min(1+minJump(nums, idx+i) , ans);
        }
        
        return dp[idx] = ans;
        
    }
    
    int jump(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        return minJump(nums, 0);
    }
};
class Solution {
    unordered_map <int,int> dp;
    unordered_set <int> s;
public:
    
    
    int maxChain(int x){
        
        if( dp.count(x) )
            return dp[x];
        
        if( s.count(x+1) > 0 )
            return dp[x] = 1 + maxChain(x+1);
        
        return dp[x] = 1;
    }
    
    int longestConsecutive(vector<int>& nums) {
        
        for( int x : nums )
            s.insert(x);
        int ans = 0;
        for( int x : nums ){
            ans = max(ans,maxChain(x));
        }
        return ans;
    }
};
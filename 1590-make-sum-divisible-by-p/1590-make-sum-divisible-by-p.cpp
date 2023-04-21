const int INF = 1e9;
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(); 
        long total = accumulate(nums.begin(),nums.end(),0*1LL);
        int rr = total%p ; // required remainder
        if( rr == 0 )
            return 0;
        
        int ans = INF, sum = 0;
        unordered_map <int,int> ls;
        ls[0] = -1;
        
        for( int i = 0 ; i < n ; i++){
            
            sum = (sum%p + nums[i]%p)%p;
            int req = (sum-rr+p)%p;
            
            if ( ls.count(req) > 0 ) {
                ans = min(ans, i-ls[req]);
            }
            
            ls[sum] = i;
        }
        
        return ans < n ? ans : -1;
    }
};
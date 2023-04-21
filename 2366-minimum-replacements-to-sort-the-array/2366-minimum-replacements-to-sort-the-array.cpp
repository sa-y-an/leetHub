typedef long long ll;
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        ll n = nums.size();
        ll mini = nums.back();
        ll ans = 0;
        for( int i = n-2 ; i >= 0 ; i--){
            if( nums[i] <= mini )
                mini = nums[i];
            else{
                ll x = ceil(nums[i]/(mini*1.0));
                ans += x-1;
                mini = nums[i]/x;
            }
        }
        
        return ans;
    }
};
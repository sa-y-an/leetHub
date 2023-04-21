class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set <int> uset;
        
        int l = 0, r = 0;
        const int n = nums.size();
        int ans = 0;
        int curr = 0;
        while( r < n){
        
            while( r < n and uset.count(nums[r]) == 0 ){
                curr += nums[r];
                uset.insert(nums[r]);
                r++;
                ans = max(ans, curr);
            }
            while( r < n and l < r and nums[l] != nums[r] ){
                curr -= nums[l];
                uset.erase(nums[l]);
                l++;
            }
            
            uset.erase(nums[l]);
            curr -= nums[l];
            l++;
            
        }
        
        return ans;
        
    }
};
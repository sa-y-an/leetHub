class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        int l = 0 , r = 1 , n = nums.size();
        
        while( l < n and r < n ){
            while( l < n and nums[l]%2 == 0 ) l+= 2;
            while( r < n and nums[r]%2 == 1 ) r+=2;
            if( l < n and r < n )
                swap(nums[l],nums[r]);
        }
        
        return nums;
    }
};
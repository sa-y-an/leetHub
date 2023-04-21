class Solution {
public:
    bool canBeIncreasing(vector<int>& nums, int prev = 0, 
                         int ll = 0, int start = 0 ) {
        
        int n = nums.size();
        for( int i = start ; i < n ; i++){
            if( nums[i] > prev ){
                prev = nums[i];
                continue;
            }else if( ll == 0 ) {
                if( i >= 2 ) prev = nums[i-2];
                else prev = 0;
                return canBeIncreasing(nums, prev, 1, i) or 
                    canBeIncreasing(nums, nums[i-1], 1,i+1);
            }
            else return false;
        }
        return true;
    }
};
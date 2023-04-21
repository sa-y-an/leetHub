class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0 , h = nums.size()-1;
        while( l <= h ){
            int mid = l + ( h - l )/2;
            if( nums[mid] > target ) h = mid-1;
            else if( nums[mid] < target ) l = mid+1;
            else return mid;
        }
        return -1;
    }
};
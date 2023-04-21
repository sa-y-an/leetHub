class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), pos = -1;
        
        for( int i = 0 ; i < n ; i++ ){
            if( nums[i] >= 0 ) {
                pos = i;
                break;
            }
        }
        
        vector <int> arr;
        if( pos == -1 ){
            for( int x : nums) arr.push_back(x*x);
            reverse(arr.begin(),arr.end());
            return arr;
        }
        int r = pos, l = pos-1;
        
        while( r < n and nums[r] == 0 ) arr.push_back(0), r++; 
        
        while( l >= 0 || r < n ){
            if( l >= 0 and (r >= n || abs(nums[l]) < abs(nums[r]) ) ) 
                arr.push_back(nums[l]*nums[l]), l--;
            else 
                arr.push_back(nums[r]*nums[r]), r++;
        }
        
        return arr;
    }
};
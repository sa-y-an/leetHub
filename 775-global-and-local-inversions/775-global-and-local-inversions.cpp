class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        vector <int> arr= nums;
        sort(arr.begin(),arr.end());
        int n = nums.size();
        
        for( int i = 0 ; i < n ; i++){
            if( abs(nums[i]-arr[i]) >1 )
                return false;
        }
        
        return true;
    }
};
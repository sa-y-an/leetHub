class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int arr[n+2];
        memset(arr, 0,sizeof(arr));
        for( int i = 0 ; i < n ; i++){
            if(nums[i] < 1 || nums[i] > n+1 ) nums[i] = 0;
            else arr[nums[i]]++;
        }
        
        for( int i = 1 ; i < n+2 ; i++){
            if( arr[i] == 0 ) 
                return i;
        }
        
        return n+1;
    }
};
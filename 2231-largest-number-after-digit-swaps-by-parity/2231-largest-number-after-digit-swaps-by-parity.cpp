class Solution {
public:
    int largestInteger(int num) {
        
        vector <int> nums,even,odd;
        while( num ) {
            int x = num%10;
            num /= 10, nums.push_back(x);
            x%2 == 0 ? even.push_back(x) : odd.push_back(x);
        }
        
        int ans =0, p= 0, e = 0 , o = 0,n = nums.size();;
        
        reverse(nums.begin(), nums.end());
        sort(even.begin(), even.end(), greater <int> ());
        sort(odd.begin(),odd.end(), greater <int> ());
        
        for( int i = 0 ; i < n ; i++) 
            nums[i]%2 == 0 ? nums[i] = even[e++] : nums[i] = odd[o++];
        
        for( int i = n-1 ; i >= 0 ; i--,p++) ans += nums[i]*pow(10,p);
        return ans;
    }
};
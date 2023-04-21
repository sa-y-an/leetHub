class Solution {
public:
    
    bool isPossible(vector <int> &nums, int l , int r ){
        
        if( l == r ) return false;
        vector <int> arr;
        
        for( int i = l ; i <= r ; i++){
            arr.push_back(nums[i]);
        }
        
        if(arr.size() == 2 ) return true;
        sort(arr.begin(),arr.end());
        int diff = arr[1]-arr[0];
        int n = arr.size();
        for( int i = 1; i < n-1 ; i++){
            if( arr[i+1]-arr[i] != diff) return false;
        }
        return true;
    
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector <bool> ans;
        for ( int i = 0 ; i < n ; i++){
            ans.push_back(isPossible(nums,l[i],r[i]));
        }
        return ans;
    }
};
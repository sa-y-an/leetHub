class Solution {
public:
    
    vector <int> smallestLeftIdx(vector <int> &nums){
        
        int n = nums.size();
        vector <int> nse(n,-1);
        stack <int> s;
        s.push(0);
        for( int i = 1 ; i < n ; i++){
            while( !s.empty() and nums[s.top()] >= nums[i] )
                s.pop();
            if( !s.empty() )
                nse[i] = s.top();
            s.push(i);
        }
        
        return nse;
    }
    
    vector <int> smallestRightIdx(vector <int> &nums){
        
        int n = nums.size();
        vector <int> nse(n,n);
        stack <int> s;
        s.push(n-1);
        for( int i = n-2 ; i >= 0 ; i--){
            while( !s.empty() and nums[s.top()] >= nums[i] )
                s.pop();
            if( !s.empty() )
                nse[i] = s.top();
            s.push(i);
        }
        
        return nse;
    }
    
    int maximumScore(vector<int>& nums, int k) {
        
        int ans = 0;
        int n = nums.size();
        vector <int> leftIdx = smallestLeftIdx(nums);
        vector <int> rightIdx = smallestRightIdx(nums);
        
        for( int i = 0 ; i < n ; i++ ){
            int l = leftIdx[i];
            int r = rightIdx[i];
            int width = min(n, r-l-1);
            int currArea = width*nums[i];
            if( k > l and r > k )
                ans = max({currArea,nums[i],ans});
        }
        
        return ans;

    }
};
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
    
    int largestRectangleArea(vector<int>& heights) {
        
        int ans = 0;
        int n = heights.size();
        vector <int> leftIdx = smallestLeftIdx(heights);
        vector <int> rightIdx = smallestRightIdx(heights);
        
        for( int i = 0 ; i < n ; i++ ){
            int l = leftIdx[i];
            int r = rightIdx[i];
            int width = min(n, r-l-1);
            int currArea = width*heights[i];
            ans = max({currArea,heights[i],ans});
        }
        
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size() , m = matrix[0].size();
        vector <int> dp(m,0);
        
        int ans = 0;
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                if( matrix[i][j] == '0' )
                    dp[j] = 0;
                else 
                    dp[j] += 1;
            }
            ans = max(largestRectangleArea(dp),ans);
        }
        
        return ans;
    }
};
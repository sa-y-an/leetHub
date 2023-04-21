class Solution {
public:
    
    vector <int> generateLis(vector <int> &nums){
        
        int n = nums.size();
        vector <int> lis, ans(n,0);
        
        for( int i = 0 ; i < n ; i++){
            int num = nums[i];
            auto lb = lower_bound(lis.begin(),lis.end(),num);
            if( lb == lis.end()){
                lis.push_back(num);
                ans[i] = lis.size();
            }
            else {
                int idx = lb - lis.begin();
                lis[idx] = num;
                ans[i] = idx+1;
            }  
        }

        return ans;
    }
    
    
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n = nums.size();
        vector <int> prefix = generateLis(nums);
        reverse(nums.begin(),nums.end());
        vector <int> suffix = generateLis(nums);
        reverse(suffix.begin(),suffix.end());
        
        int ans = n;
        for( int i = 1 ; i < n ; i++){
            if( prefix[i] > 1 and suffix[i] > 1){
                ans = min(ans, n - (prefix[i]+suffix[i]-1));
            }
        }
        
        return ans; 
    }
};
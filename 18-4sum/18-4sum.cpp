class Solution {
public:
    
    vector <vector <int>> threeSum(vector <int> &nums, int target , int start){
        
        int n = nums.size();
        vector <vector <int>> ans;
        for( int i = start ; i < n-2 ; i++){
            if( i > start and nums[i] == nums[i-1] ) continue;
            int _sum = target - nums[i], l = i+1 , r = n-1;
            while( l < r){
                if( nums[l]+nums[r] == _sum ) {
                    ans.push_back({nums[i],nums[l],nums[r]});

                    do{l++;} while(nums[l] == nums[l-1] and l < r);
                    do{r--;} while(nums[r] == nums[r+1] and l < r);
                }
                else if( nums[l] + nums[r] > _sum ) r--;
                else l++;
            }
        }
        return ans;   
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector <vector <int>> ans;
        
        for( int i = 0 ; i < n-3 ; i++ ){
            if( i > 0 and nums[i] == nums[i-1] ) continue;
            auto vec = threeSum(nums,target-nums[i], i+1);
            if( vec.size() > 0 ){
                for( auto &v : vec ){ 
                    v.push_back(nums[i]);
                    ans.push_back(v);
                }
            }
        }
        
        return ans;
    }
};
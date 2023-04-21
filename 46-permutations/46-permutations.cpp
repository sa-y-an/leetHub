class Solution {
    vector <vector<int>> ans;
public:
    
    void permHelper(vector <int> & nums, const int idx = 0 ){
        if( idx == nums.size()-1 and nums.size() ) ans.push_back(nums);
        else {
            for( int i = idx ; i < nums.size() ; i++){
                swap(nums[i],nums[idx]);
                permHelper(nums,idx+1);
                swap(nums[i],nums[idx]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        permHelper(nums);
        return ans;
    }
};
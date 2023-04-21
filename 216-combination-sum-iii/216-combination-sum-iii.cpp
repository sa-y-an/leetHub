class Solution {
    vector <vector <int>> combinations;
    int totalSize;
    
public:
    
    void combine(vector <int> &nums, vector <int> &combination, int target, int idx ){
        
        if( combination.size() == totalSize && target == 0 ){
            combinations.push_back(combination);
            return;
        }
        if( combination.size() >= totalSize || target < 0 || idx < 0 ) return;
        
        // take 
        int num = nums[idx];
        if( target - num >= 0 ){
            // nums.pop_back();
            combination.push_back(num);
            combine(nums,combination,target-num, idx-1);

            // not take 
            // nums.push_back(num);
            combination.pop_back();
        }
        combine(nums, combination, target, idx-1);
        
        
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        int h = 9;
        vector <int> nums(h,0);
        for( int i = 1 ; i < h+1 ; i++) nums[i-1] = i;
        
        vector <int> combination;
        totalSize = k;
        combine(nums,combination, n, h-1);
        return combinations;
    }
};
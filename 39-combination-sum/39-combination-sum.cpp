class Solution {
    vector <vector <int>> ans;
    vector <int> chosen;
public:    
    void combine(vector <int> & candidates, int target, int idx = 0){
        if( target < 0 ) return;
        if( target == 0) {
            ans.push_back(chosen);
            return;
        }
        if( idx >= candidates.size() ) return ;
        
        chosen.push_back(candidates[idx]);
        combine(candidates, target-candidates[idx], idx);
        chosen.pop_back();
        combine(candidates, target, idx+1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        combine(candidates,target);
        return ans;      
    }
};
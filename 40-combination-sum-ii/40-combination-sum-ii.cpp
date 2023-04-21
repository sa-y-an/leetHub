class Solution {
    vector <int> chosen;
    vector <vector <int>> ans;
public:
    void combine(vector <int> & candidates, int target, int idx = 0){
        if( target < 0 ) return;
        if( target == 0) {
            ans.push_back(chosen);
            return;
        }
        if( idx >= candidates.size() ) return ;
        
        chosen.push_back(candidates[idx]);
        combine(candidates, target-candidates[idx], idx+1);
        chosen.pop_back();
        
        while( idx+1 < candidates.size() and candidates[idx] == candidates[idx+1]) idx++;
        combine(candidates, target, idx+1);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        combine(candidates, target);
        return ans;
    }
};
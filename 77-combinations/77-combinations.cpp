class Solution {
    vector <vector <int>> ans;
    vector <int> chosen;
    int K;
    int N;
public:
    
    void findCombinations(int idx= 0 ){
        
        if( chosen.size() == K ) {
            ans.push_back(chosen);
            return;
        }
        if( chosen.size() > K or idx >= N) return;
        
        chosen.push_back(idx+1);
        findCombinations(idx+1);
        
        chosen.pop_back();
        findCombinations(idx+1);
    }
    
    vector<vector<int>> combine(int n, int k) {
        K = k, N = n;
        findCombinations();        
        return ans;
    }
};
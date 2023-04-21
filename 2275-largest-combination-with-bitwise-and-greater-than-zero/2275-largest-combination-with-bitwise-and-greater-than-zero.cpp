class Solution {
public:
    
    vector <int> i2b(int n){
        
        vector <int> ans(32,0);
        for( int i = 31 ; i >= 0 ; i--){
            if( ((n>>i)&1) )
                ans[i] = 1;
            else
                ans[i] = 0;
        }
        return ans;
    }
    
    int largestCombination(vector<int>& candidates) {
        
        vector <vector <int>> bin;
        for( int i : candidates ){
            bin.push_back(i2b(i));
        }
        
        int n = candidates.size();
        int maxi = 0;
        
        for( int x = 0 ; x < 32 ; x++){
            int curr = 0;
            for( int y = 0 ; y < n ; y++){
                curr += bin[y][x];
            }
            maxi = max(curr, maxi);
        }
        
        return maxi;
    }
};
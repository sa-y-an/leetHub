class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort( potions.begin(), potions.end());
        int n = potions.size();
        vector <int> ans;
        for( int x : spells ){
            
            long req = success/x + 1;
            if( success%x == 0 ) req--;
            int lb = lower_bound(potions.begin(), potions.end(), req ) - potions.begin();
            int temp = n - lb;
            ans.push_back(temp);
            
        }
        
        return ans;
    }
};
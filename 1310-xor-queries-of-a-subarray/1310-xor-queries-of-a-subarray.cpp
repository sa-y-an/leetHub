class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = arr.size();
        vector  <int> prefix(n);
        prefix[0] = arr[0];
        
        for( int i = 1; i < n ; i++)
            prefix[i] = prefix[i-1]^arr[i];
        
        vector <int> ans;
        
        for( auto &q: queries){
            int l = q[0], r = q[1];
            int temp;
            if( l > 0 )
                temp = prefix[r]^prefix[l-1];
            else
                temp = prefix[r];
            ans.push_back(temp);
        }
        
        return ans;
    }
};
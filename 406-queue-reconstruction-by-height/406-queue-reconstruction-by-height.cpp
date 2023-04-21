class Solution {
    static bool comparator( const vector <int> &a, const vector <int> &b){
        if( a[1] != b[1] )
            return a[1] < b[1];
        else
            return a[0] < b[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comparator);
        vector <vector<int>> ans;
        for( auto &v: people){
            int h = v[0], k = v[1];
            int cnt = 0, i = 0, n = ans.size();
            while( i < n and cnt <= k ){
                if( ans[i][0] >= h )
                    cnt++;
                if( cnt > k )
                    break;
                i++;
            }
            if( i == n )
                ans.push_back({h,k});
            else 
                ans.insert(ans.begin()+i,{h,k});
            
        }
        return ans;
    }
};
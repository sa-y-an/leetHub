bool comparator( pair <int, int> &a, pair <int, int> &b ){
    return a.first-a.second < b.first - b.second;
}

class Solution {
public:
    
    
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int k) {
        
        int n = capacity.size(), ans = 0;
        
        vector <pair <int, int>> v;
        for( int i = 0 ; i < n ; i++){
            v.push_back({capacity[i], rocks[i]});
        }
        
        sort(v.begin(), v.end(), comparator);
        
        for( int i = 0 ; i < n ; i++){
            int left = v[i].first-v[i].second;
            if( left == 0 ) {
                ans++;
                continue;
            }
            if( k <= 0 ) continue;           
            if( left <= k ) v[i].second += left, k -= left;
            else v[i].second += k, k = 0;
            
            if( v[i].first == v[i].second ) ans++;
        }
        
        return ans;
        
    }
};
/*
sort by difference in costs of a and b 
send the first n to a, rest to b 
*/


bool comparator ( vector <int> &a, vector <int> &b ){
    if( a[0] - a[1]  < b[0] - b[1]) return true;
    else return false;
}

class Solution {
public:   

    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), comparator);
        int n = costs.size()/2, ans = 0;
        for( int i = 0 ; i < n ; i++ ) ans += costs[i][0] + costs[i+n][1];
        return ans;
    }
};
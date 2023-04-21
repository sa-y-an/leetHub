bool comparator( vector <int> &a, vector <int> &b ){
    return a[0] < b[0];
}

pair <int, int> slope (vector <int> &a, vector <int> &b){
    int y = a[1] - b[1];
    int x = a[0] - b[0];
    int gcd = __gcd(y,x);
    y /= gcd;
    x /= gcd;
    
    return {y,x};
}

class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        
        pair <int, int> prev;
        int n = stockPrices.size();
        int ans = 0;
        
        sort( stockPrices.begin(), stockPrices.end(), comparator);
        for( int i = 1; i < n ; i++){
            auto currSlope = slope(stockPrices[i],stockPrices[i-1]);
            if( i == 1 || currSlope != prev ) ans += 1;
            prev = currSlope;
        }
        
        return ans;
        
    }
};
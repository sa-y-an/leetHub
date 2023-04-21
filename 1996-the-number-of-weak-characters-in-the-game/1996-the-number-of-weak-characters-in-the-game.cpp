class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        sort(properties.begin(), properties.end(), [](vector <int> &a,vector <int> & b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });
        const int n = properties.size();
        int maxDefense = properties[n-1][1], lastx = properties[n-1][0], ans = 0;
        int i = n-1;
        while( i >= 0 and properties[i][0] == lastx) {
            maxDefense = max(maxDefense,properties[i][1]);
            i--;
        }
        for( ; i >= 0 ; i--){
            if( properties[i][1] < maxDefense )
                ans++;
            maxDefense = max(maxDefense,properties[i][1]);
        }
        return ans;        
    }
};
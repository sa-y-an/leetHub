const int INF = 1e9;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        const int n = arr.size();
        int minDiff = INF;
        for( int i = 0 ; i < n-1 ; i++){
            minDiff = min(arr[i+1]-arr[i],minDiff);
        }
        
        vector <vector <int>> ans;
        for( int i = 0 ; i < n-1 ; i++){
            if( arr[i+1]- arr[i]  == minDiff) ans.push_back({arr[i], arr[i+1]});
        } 
        
        return ans;
        
    }
};
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if(arr.size() == 2 ) return true;
        sort(arr.begin(),arr.end());
        int diff = arr[1]-arr[0];
        int n = arr.size();
        for( int i = 1; i < n-1 ; i++){
            if( arr[i+1]-arr[i] != diff) return false;
        }
        return true;
    }
};
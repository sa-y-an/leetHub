class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort( arr.begin(), arr.end() );
        const int n = arr.size();
        vector <vector<int>> ans;
        int target =0;
        for( int i = 0 ; i < n ; i++){
            if ( i > 0 and arr[i] == arr[i-1]) continue;
            int start = arr[i];
            int rest = target - start ;
            int l = i+1 , r = n-1;
            while( l < r ){
                int temp = arr[l] + arr[r];
                if( temp > rest ) r--;
                else if( temp < rest ) l++;
                else {
                    vector <int> part = {arr[i], arr[l], arr[r]};
                    ans.push_back(part);
                    int f = arr[l];
                    while(l < r and arr[l] == f ) l++;
                }
            }
        }
        
        return ans;
    }
};
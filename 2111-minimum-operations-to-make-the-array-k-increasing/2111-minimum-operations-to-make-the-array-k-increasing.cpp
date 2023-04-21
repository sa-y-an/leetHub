class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        
        int n = arr.size(), ans = 0;
        for( int start = 0 ; start < k ; start++){
            vector <int> lis;
            int cnt = 0;
            for( int i = start ; i < n ; i += k ){
                if( lis.empty() or lis.back() <= arr[i]) 
                    lis.push_back(arr[i]);
                else {
                    int idx = upper_bound(lis.begin(),lis.end(),arr[i]) - lis.begin();
                    lis[idx] = arr[i];
                }
                cnt++;
            }
            ans += cnt-lis.size();
        }
        return ans;
    }
};
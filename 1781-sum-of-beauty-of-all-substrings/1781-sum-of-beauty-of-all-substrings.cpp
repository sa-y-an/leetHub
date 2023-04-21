const int INF = 1e3;
class Solution {
public:
    
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for( int i = 0 ; i < n ; i++){
            int _max = 1;  
            vector <int> arr(26,0);
            for( int j = i ; j < n ; j++){
                arr[s[j]-'a']++;
                _max = max(_max, arr[s[j]-'a']);
                if( _max == 1 ) continue;
                
                
                int _min = INF;
                for( int i = 0 ; i < 26 ; i++) {
                    if( arr[i] == 0 ) continue;
                    if( arr[i] == 1 ) {
                        _min = 1;
                        break;
                    }
                    _min = min(_min,arr[i]);
                }

                ans += _max-_min;
            }
        }
        
        return ans;
    }
};
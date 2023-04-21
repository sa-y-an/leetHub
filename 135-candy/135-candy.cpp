class Solution {
public:
    
    int candy(vector<int>& a) {
        
        int n = a.size();
        vector <int> ans(n,0), valleys;
        
        for( int i = 0 ; i < n ; i++){
            if( ( i+1 == n || a[i] <= a[i+1] ) and 
               ( i == 0 || a[i] <= a[i-1]) ){
                valleys.push_back(i);
            }
        }
        
        for( int i = 0 ; i < valleys.size() ; i++){
            
            int idx = valleys[i];
            ans[idx] = 1;
            int rating = 2;
            int l = idx-1;
            while( l >= 0 ){
                if( a[l] == a[idx] )
                    break; 
                if( l == 0 || a[l-1] <= a[l] ){
                    if( ans[l] < rating )
                        ans[l] = rating;
                    break;
                }else {
                    ans[l] = rating;
                    l--, rating++;
                }
            }
            rating = 2;
            int r = idx+1;
            while( r < n ){ 
                if( a[r] == a[idx] )
                    break;
                if( r == n-1 || a[r+1] <= a[r] ){
                    if( ans[r] < rating )
                        ans[r] = rating;
                    break;
                }else {
                    ans[r] = rating;
                    r++, rating++;
                }
            }
            
        }
        
        return accumulate(ans.begin(), ans.end(), 0);
    }
};
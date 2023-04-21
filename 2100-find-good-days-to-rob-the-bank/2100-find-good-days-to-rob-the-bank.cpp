class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& arr, int k) {
        
        int i = 0 , n = arr.size(), prev = 0;
        if( k == 0 ){
            vector <int> ans(n,0);
            for( int i = 0 ; i < n ; i++)
                ans[i] = i;
            return ans;
        }       
        
        vector <int> ans;
        while( i < n ){
            
            // decreasing
            int dec = 0;
            while( i+1 < n and arr[i+1] < arr[i] ){
                dec++, i++;
            }
            dec += prev;
                
            int l = i;
            int equal = 0;
            while( i < n and arr[i] == arr[l] ){
                equal++, i++;
            }
            
            int r = i;
            int inc = 0;
            while( i > 0 and i < n and arr[i] >= arr[i-1])
                inc++, i++;
            
            prev = 0;
            if( inc ){
                int idx = i-1;
                int end = arr[idx];
                while( arr[idx] == end )
                    idx--, prev++;
            }
            
            if( equal == 1 and dec >= k and inc >= k ){
                ans.push_back(l);
                continue;
            }
            
            if( dec < k )
                l += k-dec;
            if( inc < k )
                r -= k-inc;
            
            for( int idx = l ; idx < r ; idx++ ){
                ans.push_back(idx);
            }
            
        }
        
        if( prev ){
            int l = n-prev;
            for( int i = l+k ; i < n-k ; i++){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
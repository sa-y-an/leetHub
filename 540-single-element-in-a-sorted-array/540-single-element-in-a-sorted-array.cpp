class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int i = 0 , n = arr.size();
        
        while( i < n ){
            int start = arr[i];
            int cnt = 0;
            while( i < n and start == arr[i] ) i++, cnt++;
            if( cnt == 1 ) return arr[i-1];
        }
        
        return -1;
    }
};
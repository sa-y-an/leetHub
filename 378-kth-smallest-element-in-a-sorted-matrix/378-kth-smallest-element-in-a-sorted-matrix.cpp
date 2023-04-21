class Solution {
public:
    
    int numRank(vector<vector<int>>& matrix, int num ){
        
        int n = matrix.size();
        int cnt = 0;
        for( int i = 0 ; i < n ; i++ ){
            cnt += upper_bound(matrix[i].begin(), matrix[i].end(), num) 
                - matrix[i].begin();
        }
        
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int low = matrix[0][0] , high = matrix[n-1][n-1];
        int ans = low;
        while( low <= high ){
            
            int mid = (low+high)/2;
            if( numRank(matrix,mid) >= k ){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};
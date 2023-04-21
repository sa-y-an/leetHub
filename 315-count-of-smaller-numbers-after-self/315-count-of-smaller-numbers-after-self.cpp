typedef pair <int,int> pi;
class Solution {
    vector <int> ans;
    vector <pi> arr;
public:
     
    void merge(int l,int mid, int r){
        
        int prev = 0;
        int l1 = l , r1 = mid , l2 = mid+1 , r2 = r;
        while( l1 <= r1 ){
            
            ans[arr[l1].second] += prev;
            int cnt = 0;
            while( l2 <= r2 and arr[l2].first < arr[l1].first ){
                l2++, cnt++;
            }
            prev += cnt;
            ans[arr[l1].second] += cnt;
            l1++;
        }
        
        inplace_merge(arr.begin()+l,arr.begin()+mid+1, arr.begin()+r+1); 
    }
    
    void msort(int l,int r){
        
        if( l >= r )
            return;
        
        int mid = l + (r-l)/2;
        msort(l,mid);
        msort(mid+1,r);
        merge(l,mid,r);
    }
    
    
    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();
        ans.resize(n,0);
        for( int i = 0 ; i < n ; i++ )
            arr.push_back({nums[i],i});
        
        msort(0,n-1);
        return ans;
    }
};
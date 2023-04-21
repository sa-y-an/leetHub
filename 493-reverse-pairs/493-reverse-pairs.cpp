class Solution {
public:
    
    int merge( int l1 , int r1, int l2,int r2, vector <int> &arr){

      vector <int> ans;
      int idx = l1, res = 0;
      
      // counting step
      int mid = r1;
      int total = 0;
      int j = mid + 1;
      for (int i = l1; i <= mid; i++) {
        while (j <= r2 && arr[i] > 2* 1LL * arr[j]) {
          j++;
        }
        total += (j - (mid + 1));
      }
        
      // merge step 
      int low = l1, high = r2;
      while( l1 <= r1 || l2 <= r2 ) {   
        if( (l1 <= r1) and ( l2 > r2 || arr[l1] < arr[l2] )){
          ans.push_back(arr[l1++]);
        }else{
          ans.push_back(arr[l2++]);
        }
      }
      
      for( int i = low ; i <= high ; i++)
          arr[i] = ans[i-low];
      
      
      return total;
    }


    int msort( int l ,int r, vector <int> &arr){

      if( l >= r )
        return 0;

      int mid = l + (r-l)/2;
      int left = msort(l,mid,arr);
      int right = msort(mid+1,r,arr);
      int my = merge(l,mid,mid+1,r,arr);

      return left+right+my;
    }


    
    int reversePairs(vector<int>& nums) {
        
        int n = nums.size();
        return msort(0,n-1,nums);
    }
};
class Solution {
public:
    
    vector <int> merge(vector <int> &nums1, vector <int> &nums2){
        
        int l = 0, r = 0 , n1 = nums1.size(), n2 = nums2.size();
        vector <int> ans;
        
        while( l < n1 or r < n2 ){
            
            if( r < n2 and (l == n1 or nums1[l] > nums2[r]) )
                ans.push_back(nums2[r++]);
            else
                ans.push_back(nums1[l++]);            
        }
        
        return ans;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector <int> arr = merge(nums1,nums2);
        int n = arr.size();
        
        if( n%2 == 0 ){
            double one = arr[n/2];
            double two = arr[n/2 - 1 ];
            return (one+two) / 2;
        }else{
            return (double) arr[n/2];
        }
    }
};
const int m = 1e9+7;
const int INF = 1e6+7;
class Solution {
    vector <int> nums;
public:
    int closest(int target){
        int l = 0 , r = nums.size()-1;
        int ans = INF;
        while( l <= r ){
            int mid = l + (r-l)/2;
            if( nums[mid] == target ) return 0;
            else if( target > nums[mid] ) l = mid+1;
            else r = mid-1;
            ans = min(ans, abs(nums[mid]-target));
        }
        return ans;
    }
    
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        
        nums = nums1;
        sort(nums.begin(),nums.end());
        long sum = 0;
        int n = nums1.size(), maxDiff = 0;
        
        for( int i = 0 ; i < n ; i++){
            int diff = abs(nums1[i]-nums2[i]);
            sum += (diff*1LL);
            int closestDiff = closest(nums2[i]);
            maxDiff = max(diff-closestDiff,maxDiff);
        }
        
        return (sum-maxDiff)%m;
    }
};
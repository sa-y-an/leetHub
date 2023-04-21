#define ll long long 
class Solution {
public:
    
    bool isPossible( vector <int> & candies, int req, int k){
        
        int grps = 0;
        for( auto num : candies){
            if( num < req ) continue;
            grps += num/req;
            if( grps >= k ) return true;
        }
        
        return grps >= k;
        
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        
        
        ll total = 0;
        for( auto candy : candies ) {
            ll temp = candy;
            total += candy;
        }
        if( total < k ) return 0;
        
        ll high = total/k;
        int h = high, l = 1;
        
        int ans = 0;
        while( l <= h ){
            int mid = l + (h-l)/2;
            if( isPossible(candies,mid,k)){
                ans = mid;
                l = mid+1;
            }
            else h = mid-1;
        }
        
        return ans;
    }
};
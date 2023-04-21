typedef long long ll;
const int INF = 1e9+7;
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        
        ll total = 0, diff = 0;
        nums.push_back(0);
        make_heap(nums.begin(), nums.end(), greater <ll> ());
        ll idx = 0;
        
        while( idx < k ){
            ll first = nums.front(), second = INF;
            pop_heap(nums.begin(), nums.end(),greater <ll>());
            nums.pop_back();
            
            if( nums.size() > 0 ) 
                second = nums.front();
            
            diff = min(k-idx,second-first-1);
            if( diff < 0 ) diff = 0;
            total += ((2*(first+1) + (diff-1))*(diff))/2;
            idx += diff;

        }
        
        return total;
    }
};
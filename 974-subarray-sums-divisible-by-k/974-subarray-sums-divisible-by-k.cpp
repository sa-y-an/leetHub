/*
sum(i,j) = (p[j] - p[i-1])%k
13 - 8 
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map <int, int> seen;
        seen[0] = 1;
        
        int sum = 0, ans =0 ;
        
        for( int x : nums ){
            sum += x;
            int rem = sum%k;
            if( rem < 0 ) rem += k;
            
            if( seen.count(rem) > 0 ){
                ans += seen[rem];
            }
            seen[rem]++;
        }
        return ans;
    }
};
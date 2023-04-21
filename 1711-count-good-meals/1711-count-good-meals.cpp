const int m = 1e9+7;
class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int, int> cnts;
        int ans = 0;
        
        for( int i = 0 ; i < n ; i++){
            
            int num = nums[i];
            for( int j = 0; j <= 21 ; j++){
                int target = pow(2,j)-num;
                if( cnts.count(target) > 0 )
                    ans = (ans%m + (cnts[target]%m))%m;
            }
            
            cnts[num]++;
        }
        
        return ans;
    }
};
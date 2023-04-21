/*
- Use kadane on positive of array 
- Use kadane on negative of array
- return max
*/
const int INF = 1e9;
class Solution {
public:
    

    int kadane(vector <int> &nums){
        
        int ans = -1*INF, currSum = -1*INF;
        for( auto num : nums ){
            currSum += num;
            currSum = max(currSum, num);
            ans = max(currSum, ans);
            if( currSum < 0 ) currSum = 0;
        }
        
        return ans;
    }
    
    
    int maxAbsoluteSum(vector<int>& nums) {
        
        int pos = kadane(nums);
        for( auto &num : nums) num *= -1;
        int neg = kadane(nums);
        
        return max(pos, neg);
        
    }
};
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        int maxNegative =0;
        int currSum = 0;
        for( auto num : nums){
            currSum += num;
            maxNegative = min(maxNegative, currSum);
        }
        
        return (-1*maxNegative)+1;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int arrSum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        int totalSum = (n*(n+1))/2;
        return totalSum-arrSum;
    }
};
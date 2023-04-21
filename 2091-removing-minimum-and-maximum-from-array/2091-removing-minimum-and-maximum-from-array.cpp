class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minPos = min_element(nums.begin(),nums.end()) - nums.begin(),
            maxPos = max_element(nums.begin(),nums.end()) - nums.begin();
        
        int n = nums.size(),
        front = max(minPos, maxPos)+1,
        back = n-min(minPos,maxPos),
        comb = n-max(minPos, maxPos)+ min(minPos,maxPos)+1;
        
        return min({front,back,comb});
        
    }
};
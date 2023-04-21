const int INF = 1e6;

class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int cnt = 0, start = 0, diff = 0, i = 0, reqNum = 0;
        
        while( cnt < k and i < nums.size()){
            reqNum = start;
            diff = min(nums[i]-start-1, k-cnt);
            cnt += diff;
            reqNum += diff;
            start = nums[i];
            i++;
        }
        
        if( cnt == k ) return reqNum;
        else return nums.back() + (k-cnt);
        
    }
};
const int INF = 1e9+10;
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(), ans = -1, minsf = INF;
        for( int x : nums ){
            ans = max(x-minsf, ans);
            minsf = min(minsf, x);
        }
        return ans == 0 ? -1 :ans;
    }
};
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int x : nums ){
            int digit = floor(log10(x) + 1);
            if( digit%2 == 0 ) ans++;
        }
        return ans;
    }
};
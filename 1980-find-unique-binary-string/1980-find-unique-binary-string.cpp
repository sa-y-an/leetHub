class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans(n,'0');
        for( int i = 0 ; i < n ; i++){
            if( nums[i][i] == '1') ans[i] = '0';
            else ans[i] = '1';
        }
        return ans;
    }
};
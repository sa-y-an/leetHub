class Solution {
public:
    int findMinDifference(vector<string>& time) {
        
        vector <short> nums;
        for( auto &s : time) nums.push_back(stoi(s.substr(0,2))*60 + stoi(s.substr(3,2)));
        sort(nums.begin(), nums.end());
        int ans =  abs( nums[0]+1440 - nums.back() );
        for( int i = 1 ; i < nums.size() ; i++) ans = min(ans, nums[i]-nums[i-1]);
        return ans;
    }
};
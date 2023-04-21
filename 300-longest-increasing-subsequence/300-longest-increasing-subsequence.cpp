class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector <int> lis;
        for( int x : nums ){
            auto it = lower_bound(lis.begin(),lis.end(),x);
            if( it == lis.end() ) lis.push_back(x);
            else lis[it-lis.begin()] = x;
        }
        return lis.size();
    }
};
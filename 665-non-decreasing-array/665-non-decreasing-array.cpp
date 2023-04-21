class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        vector <int> lis;
        for( int x : nums ){
            auto ub = upper_bound(lis.begin(), lis.end(), x);
            if( ub == lis.end() )
                lis.push_back(x);
            else{
                int idx = ub - lis.begin();
                lis[idx] = x;
            }
        }
        return lis.size() == nums.size()-1 or lis.size() == nums.size();
    }
};
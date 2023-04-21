const int INF = INT_MAX;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INF, mid = INF;
        for( int num : nums ){
            if( num <= small ) small = num;
            else if( num <= mid ) mid = num;
            else return true;
        }
        return false;
    }
};


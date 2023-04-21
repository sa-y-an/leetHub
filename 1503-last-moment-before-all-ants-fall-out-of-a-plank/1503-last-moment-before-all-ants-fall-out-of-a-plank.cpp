class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int r = 0;
        if( right.size() > 0 )
            r = n-*min_element(right.begin(),right.end());
        int l = 0;
        if( left.size() > 0 )
            l = *max_element(left.begin(),left.end());
        return max(l,r);
    } 
};
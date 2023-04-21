const long INF = -1e10;
class Solution {
public:
    int thirdMax(vector<int>& nums) {

		long x1 = INF, x2 = INF, x3 = INF;

		for( int x : nums ){
			if( x == x3 or x == x2 ) continue;
			if( x > x3 ) {
				x1 = x2;
				x2 = x3;
				x3 = x;
			}
			else if( x > x2 ){
				x1 = x2;
				x2 = x;
			}
			else if( x > x1 ){
				x1 = x;
			}
			
		}
        
        if( x1 == INF ) return x3;
        return x1;
    }
};
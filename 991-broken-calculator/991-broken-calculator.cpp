class Solution {
public:       
    int brokenCalc(int start, int target) {
        int k = 0;
        while( target > start ){
            if( target%2 == 0 ) target /= 2, k++;
            else target = (target+1)/2 , k += 2;
        }
        return k+(start-target);
    }
};
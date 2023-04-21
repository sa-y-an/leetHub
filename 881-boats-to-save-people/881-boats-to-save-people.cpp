class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l = 0 , r = people.size()-1,boatCnt = 0;
        sort( people.begin() , people.end());
        while( l < r ){
            if( people[l]+people[r] <= limit) boatCnt++, l++, r--;
            else r--;
        }
        return people.size() - boatCnt;       
    }
};
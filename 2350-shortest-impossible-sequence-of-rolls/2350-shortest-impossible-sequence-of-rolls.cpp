class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        
        unordered_set <int> s;
        int occ = 0;
        for( auto roll : rolls ){
            s.insert(roll);
            if( s.size() == k ){
                occ++;
                s.clear();
            }
        }
        return occ+1;
    }
};
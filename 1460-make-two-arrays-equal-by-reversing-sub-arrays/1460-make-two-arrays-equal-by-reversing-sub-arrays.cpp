class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map <int,int> tmap,amap;
        for( auto x : target ) tmap[x]++;
        for( auto x : arr ) amap[x]++;
        return amap == tmap;
    }
};
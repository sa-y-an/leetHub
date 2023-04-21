bool comparator(vector <int> &a , vector <int> &b){
    if( a[1] > b[1]) return true;
    else return false;
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), comparator);
        int i = 0;
        int leftOver = truckSize;
        int ans=0;
        int n = boxTypes.size();
        while( leftOver > 0 and i < n ){
            
            if( leftOver - boxTypes[i][0] > 0 ) {
                ans += boxTypes[i][1]*boxTypes[i][0];
                leftOver -= boxTypes[i][0];
                i++;
            }
            else {
                ans += boxTypes[i][1]*leftOver;
                leftOver = 0;
                i++;
            }
            
        }
        
        
        return ans;
        
    }
};
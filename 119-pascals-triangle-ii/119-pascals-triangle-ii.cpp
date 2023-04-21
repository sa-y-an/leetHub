class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector <int> prev;
        for( int i = 1 ; i <= rowIndex+1 ; i++){
            vector <int> temp(i,0);
            temp[0] = 1; temp[i-1] = 1;
            for( int idx = 1 ; idx < i-1 ; idx++){
                temp[idx] = prev[idx] + prev[idx-1];
            }
            prev = temp;
        }
        return prev;
    }
};
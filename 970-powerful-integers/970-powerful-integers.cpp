class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        
        if( bound < 2 )
            return {};
        
        int limx = x != 1 ? log(bound-1)/log(x) : -1;
        int limy = y != 1 ? log(bound-1)/log(y) : -1;
        
        set <int> ans;
        for( int i = 0 ; i < limx + 2 ; i++ ){
            for( int j = 0 ; j < limy + 2 ; j++ ){
                int curr = pow(x,i) + pow(y,j);
                if( curr <= bound ){
                    ans.insert(curr);
                }
            }
        }
        
        return vector <int> (ans.begin(),ans.end());
    }
};
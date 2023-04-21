class Solution {
public:
    
    vector <int> i2b(int n){
        
        vector <int> ans(32,0);
        for( int i = 31 ; i >= 0 ; i--){
            if( ((n>>i)&1) )
                ans[i] = 1;
        }
        return ans;
    }
    
    int maximumXOR(vector<int>& nums) {
        
        vector <vector<int>> bin;
        for( int x : nums ){
            bin.push_back(i2b(x));
        }
        int n = nums.size();
        
        vector <int> arr(32,0);
        for( int x = 31 ; x >= 0 ; x--){
            int curr = 0;
            for( int y = 0 ; y < n ; y++){
                if( bin[y][x] ){
                    curr = 1;
                    break;
                }
            }
            arr[x] = curr; 
        }
        
        int ans = 0;
        for( int i = 0 ; i < 32 ; i++){
            ans += (pow(2,i)*(arr[i]));
        }
        
        return ans;
    }
};
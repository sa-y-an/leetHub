class Solution {
    vector <vector<int>> dict;
public:
    
    void generate(){
        for( int i = 0 ; i < 32 ; i++){
            long digit = pow(2,i);
            while( digit ){
                int place = digit%10;
                digit /= 10;
                dict[i][place]++;
            }
        }
    }
    
    bool reorderedPowerOf2(int n) {
        
        dict.resize(32, vector <int> (10,0));
        generate();
        vector <int> inputArr(10,0);
        while( n ){
            int place = n%10;
            n/= 10;
            inputArr[place]++;
        }
        
        for( int i = 0 ; i < 32 ; i++){
            if( dict[i] == inputArr){
                return true;
            }
        }
        
        return false;
    }
};
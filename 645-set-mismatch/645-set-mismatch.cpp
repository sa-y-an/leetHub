class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        long long n = arr.size();
        int repeat = n+1;

        for( int i = 0 ; i < arr.size() ; i++){
            int idx = abs(arr[i])-1;
            if( arr[idx] < 0 ) {
                repeat = idx+1;
                break;
            }
            arr[idx] *= -1;
        }

        long long theory = (n*(n+1)*1LL)/2;
        long long acc =0;

        for( int x : arr) acc += abs(x);

        int missing = theory-(acc-repeat);
        return {repeat,missing};
    }
};
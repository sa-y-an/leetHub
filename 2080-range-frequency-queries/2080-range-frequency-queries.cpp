class RangeFreqQuery {
    unordered_map <int, vector <int>> mpp;
public:
    
    RangeFreqQuery(vector<int>& arr) {
        for( int i = 0 ; i < arr.size() ; i++)
            mpp[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        
        vector <int> &arr = mpp[value];
        return upper_bound(arr.begin(),arr.end(),right) - lower_bound(arr.begin(),arr.end(),left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
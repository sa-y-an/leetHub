class CountIntervals {
    map <int, int> mpp;
    int cnt;
public:
    CountIntervals() {
        cnt = 0;
    }
    
    void add(int left, int right) {
        auto lb = mpp.lower_bound(left);
        
        if( lb == mpp.end() || lb->second > right ){
            mpp[right] = left;
            cnt += right-left+1;
        }
        else {
            
            while( lb != mpp.end() and lb->second <= right ){
                left = min(left, lb->second);
                right = max(right, lb->first);
                cnt -=  lb->first - lb->second + 1;
                mpp.erase(lb++);
            }
            
            mpp[right] = left;
            cnt += right-left+1;
        }
        
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
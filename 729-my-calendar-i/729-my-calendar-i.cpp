class MyCalendar {  
    map <int,int> mpp; // end date, start date
public:
    MyCalendar() {
        
    }
    bool book(int start, int end) {
        
        auto lb = mpp.lower_bound(start);
        if( lb != mpp.end() and lb->first == start )
            return false;
        if( lb != mpp.end() and lb->second <= end-1 )
            return false;
        
        mpp[end-1] = start;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
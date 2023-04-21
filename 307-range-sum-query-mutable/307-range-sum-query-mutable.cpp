class NumArray {
    vector <int> seg;
    int N;
public:
    
    void build(vector <int> &nums, int low, int high, int idx){
        
        if( low == high ){
            seg[idx] = nums[low];
            return;
        }
        
        int mid = (low+high)/2;
        build(nums, low,mid,2*idx+1);
        build(nums, mid+1,high, 2*idx + 2);
        seg[idx] = seg[2*idx + 1 ] + seg[2*idx + 2];
    }
    
    // use given range to navigate to pt, consider 3 overlap cases
    int getSum( int cl, int cr, const int & l, const int & r, int idx){
        
        // complete overlap
        if( cl >= l and cr <= r )
            return seg[idx];
        else if( cr < l or r < cl ) // no overlap
            return 0;
        else{
            int mid = (cr+cl)/2;
            int left = getSum(cl, mid, l, r, 2*idx + 1);
            int right = getSum(mid+1, cr, l, r, 2*idx +2 );
            return left + right;
        }
        
    }
    
    // use arrIdx and segIdx to navigate to the pt
    void segUpdate(int low, int high, const int arrIdx, 
                   int segIdx,const int val){
        
        if( low == high){
            seg[segIdx] = val;
            return;
        }
        
        int mid = (low+high)/2;
        if( arrIdx <= mid )
            segUpdate(low, mid, arrIdx, 2*segIdx+ 1 , val);
        else
            segUpdate(mid+1, high, arrIdx, 2*segIdx + 2 , val);
        
        seg[segIdx] = seg[2*segIdx + 1 ] + seg[2*segIdx + 2];
    }
    
    NumArray(vector<int>& nums) {
        
        int n = nums.size();
        N = n;
        int m = 4*n;
        seg.resize(m, 0);
        build(nums,0,n-1,0);        
    }
    
    void update(int index, int val) {
        segUpdate(0,N-1, index, 0, val);
    }
    
    int sumRange(int left, int right) {
        return getSum(0,N-1 ,left,right,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
class SmallestInfiniteSet {
    set <int> infy;
public:
    SmallestInfiniteSet() {
        for( int i = 1; i <= 1000 ; i++)
            infy.insert(i);
    }
    
    int popSmallest() {
        int s = *infy.begin();
        infy.erase(s);
        return s;
    }
    
    void addBack(int num) {
        infy.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
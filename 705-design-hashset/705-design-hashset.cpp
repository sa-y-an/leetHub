const int N = 1e6+10;
class MyHashSet {
    
    bool arr[N];
    
public:
    MyHashSet() {
        memset(arr,false,sizeof(arr));
    }
    
    void add(int key) {
        arr[key] = true;
    }
    
    void remove(int key) {
        arr[key] = false;
    }
    
    bool contains(int key) {
        if( arr[key ]) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
class MyHashMap {
    vector <int> hash;
public:
    MyHashMap() {
        int n = 1e6+10;
        hash.resize(n,-1);
    }
    
    void put(int key, int value) {
        hash[key] = value;
    }
    
    int get(int key) {
        return hash[key];
    }
    
    void remove(int key) {
        hash[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
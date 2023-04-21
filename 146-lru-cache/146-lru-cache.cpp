class LRUCache {
    list <int> q;
    unordered_map <int,int> mpp;
    unordered_map <int, list <int> :: iterator > idx;
    int k;
public:
    LRUCache(int capacity) {
        k = capacity;
    }
    
    int get(int key) {
        
        if( mpp.count(key) ){
            q.erase(idx[key]); 
            q.push_back(key);
            idx[key] = --q.end();
            return mpp[key];
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        
        if( mpp.count(key) ){
            q.erase(idx[key]);   
        }   
        else if( mpp.size() == k ){
            int front = q.front();
            q.pop_front();
            mpp.erase(front);
        }
        mpp[key] = value;
        q.push_back(key);
        idx[key] = --q.end();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
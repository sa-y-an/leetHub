class MyStack {
public:
    
    queue <int> q;
    int last;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        last = x;
    }
    
    int pop() {
        vector <int> temp;
        while( !q.empty()){
            temp.push_back(q.front());
            q.pop();
        }
        int n = temp.size();
        // 1 2 3 4
        //
        for( int i = 0; i < n-1 ; i++) q.push(temp[i]);
        if( n-2 >= 0 ) last = temp[n-2];
        return temp.back();
    }
    
    int top() {
        return last;
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
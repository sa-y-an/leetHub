class MinStack {
    vector <int> st, mini;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
        int temp = val;
        if( !mini.empty() and mini.back() < val )
            temp = mini.back();
        mini.push_back(temp);
    }
    
    void pop() {
        mini.pop_back();
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return mini.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
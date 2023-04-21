class MyQueue {
    vector <int> input, output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push_back(x);
    }
    
    int pop() {
        
        if( output.empty()){
            while( !input.empty()){
                int top = input.back();
                output.push_back(top);
                input.pop_back();
            }        
        }
        
        if( !output.empty()){
            int top = output.back();
            output.pop_back();
            return top;
        }
        
        return -1;
    }
    
    int peek() {

        if( output.empty()){
            while( !input.empty()){
                int top = input.back();
                output.push_back(top);
                input.pop_back();
            }        
        }

        if( !output.empty()){
            int top = output.back();
            // output.pop_();
            return top;
        }
        
        return -1;
    }
    
    bool empty() {
        return input.empty() and output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
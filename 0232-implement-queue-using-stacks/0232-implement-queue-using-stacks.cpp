class MyQueue {
public:
    std::stack<int> working; 
    std::stack<int> support;

    MyQueue() {
    }
    
    void push(int x) {
        working.push(x);
    }
    
    int pop() {
        if (support.empty()){
            while(!working.empty()){
                support.push(working.top()); 
                working.pop();
            }
        }
        int temp = support.top();
        support.pop();
        return temp;
        
    }
    
    int peek() {
        if (support.empty()){
            while(!working.empty()){
                support.push(working.top()); 
                working.pop();
            }
        }
        return support.top();
    }
    
    bool empty() {
        if (working.empty() && support.empty()) return true; 
        return false;
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
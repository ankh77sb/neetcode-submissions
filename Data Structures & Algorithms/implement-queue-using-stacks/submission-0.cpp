class MyQueue {
    stack<int> st1;
    stack<int> st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int res = -1;
        while(!st1.empty()) {
            int x =  st1.top();
            st1.pop();
            if(st1.empty()) {
                res = x;
            } else st2.push(x);
        }
        while(!st2.empty()) {
            int x =  st2.top();
            st2.pop();
            st1.push(x);
        }
        return res;
    }
    
    int peek() {
        int res = -1;
        while(!st1.empty()) {
            int x =  st1.top();
            st1.pop();
            if(st1.empty()) {
                res = x;
            }
            st2.push(x);
        }
        while(!st2.empty()) {
            int x =  st2.top();
            st2.pop();
            st1.push(x);  
        }
        return res;
    }
    
    bool empty() {
        return st1.empty();
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
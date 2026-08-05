class MinStack {
private:
    stack<int>st;
public:
    MinStack() : st() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        if(!st.empty())st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int>cp =st;
        int mini = INT_MAX;
        while(!cp.empty()){
            mini = min(mini, cp.top());
            cp.pop();
        }
        return mini;
    }
};

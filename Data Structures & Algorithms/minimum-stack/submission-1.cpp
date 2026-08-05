class MinStack {
private:
    stack<int>st;
    stack<int>minSt;
public:
    MinStack() : st(), minSt(){
        
    }
    
    void push(int val) {
        st.push(val);

        if(minSt.empty() || val <= minSt.top()){
            minSt.push(val);
        }
        else minSt.push(minSt.top());
    }
    
    void pop() {
        minSt.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

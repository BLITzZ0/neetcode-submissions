class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto &t : tokens){
            if(t == "+" || t == "-" || t == "*" || t == "/"){
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();

                if(t == "+")st.push(num1 + num2);
                else if(t == "*")st.push(num1 * num2);
                else if(t == "-")st.push(num1 - num2);
                else st.push(num1 / num2);
            }
            else st.push(stoi(t));
        }
        return st.top();
    }
};

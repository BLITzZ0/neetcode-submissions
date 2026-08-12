class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures){
        int n = temperatures.size();
        stack<int>st;
        vector<int>ans(n, 0);

        for(int i = 0; i < n; i++){

            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int index = st.top();
                st.pop();
                ans[index] = i - index;

            }
            st.push(i);
        }
        return ans;
        
    }
};

/*
->instead of storing element in stack store their index 
--->while stack ! empty and any element is greater than stack.top();
------>ans[stack.top()]  = index - i;
------>stack.pop();
*/

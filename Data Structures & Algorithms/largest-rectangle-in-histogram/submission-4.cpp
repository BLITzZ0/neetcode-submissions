class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nextSmallest(n, n);
        vector<int>previousSmallest(n, -1);

        stack<int>st;
        int max_area = 0;
        for(int i = n - 1;i >= 0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(!st.empty()){
                nextSmallest[i] = st.top();
            }

            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }

        for(int i = 0;i < n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(!st.empty()){
                previousSmallest[i] = st.top();
            }

            st.push(i);
        }

        for(int i = 0;i < n;i++){
            int curr_area = heights[i] * (nextSmallest[i] - previousSmallest[i] - 1);
            max_area = max(max_area, curr_area);
        }
        return max_area;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int max_area = 0;
        for(int i = 0;i <= n;i++){
            int curr_height = (i == n) ? 0 : heights[i];
            while(!st.empty() && heights[st.top()] > curr_height){
                int height = heights[st.top()];
                st.pop();

                int width;
                if(st.empty()){
                    width = i;
                }
                else width = i - st.top() - 1;

                int curr_area = height * width;
                max_area = max(max_area, curr_area);
            }
            st.push(i);
        }

        return max_area;
    }
};

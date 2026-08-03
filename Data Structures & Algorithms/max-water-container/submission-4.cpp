class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int max_area = 0;
        while(left < right){
            int length = right - left;
            int area = length * min(heights[left], heights[right]);
            max_area = max(max_area, area);
            if(heights[left] <= heights[right])left++;
            else right--;
        }
        return max_area;
    }
};

/*
1,7,2,5,4,7,3,6
0,1,2,3,4,5,6,7
left = 0, right = 7
-> 1 & 6 -> lenght => (7 - 0) * min(1,6) = 7 left = 1, right = 7
-> 7 & 6 -> length => (7 - 1) *min(7,6) = 36 left = 1, right = 6
-> 7 & 3 -> length => (6 - 1) * min(7,3) = 15 left = 1, right= 5
-> 7 & 7 -> length => (5 - 1) * min(7,7) = 28 left = 2, right = 5;
-> 5 & 7 -> length => (5 - 2) * min(5, 7) = 15 left = 3, right 5;
-> 4 & 7 -> length => (5 - 3) * min(4, 7) = 8 left = 4, right 5

loop out max is 36

*/


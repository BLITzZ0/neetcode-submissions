class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int left= 0, right = row * col - 1;

        while(left <= right){
            int mid = left + (right - left)/2;
            int r = mid / col;
            int c = mid % col;

            int ele = matrix[r][c];

            if(ele == target)return true;
            else if(ele > target) right = mid - 1;
            else left = mid + 1;
        }

        return false;
    }
};

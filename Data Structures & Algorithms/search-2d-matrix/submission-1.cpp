class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //find the correct row
        //binary search on that row.
        int rows = matrix.size();
        int col = matrix[0].size();

        for(int i = 0;i<rows;i++){
            if(target >= matrix[i][0]  && target <= matrix[i][col-1]){
                int left = 0, right = col-1;
                while(left <= right){
                    int mid = left + (right - left) / 2;

                    if(matrix[i][mid] == target){
                        return true;
                    }
                    if(matrix[i][mid] > target){
                        right = mid - 1;
                    }
                    else left = mid + 1;
                }
            }
        }
        return false;
    }
};

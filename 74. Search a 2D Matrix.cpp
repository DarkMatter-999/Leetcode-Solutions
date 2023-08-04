class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();

        int top = 0, bottom = row-1;
        while(top <= bottom) {
            int r = (top + bottom) / 2;
            if(target > matrix[r][col-1]) {
                top = r + 1;
            } else if(target < matrix[r][0]) {
                bottom = r - 1;
            } else {
                break;
            }
        }

        if(!(top <= bottom)) return false;

        int r = (top + bottom) / 2;
        int left = 0, right = col - 1;
        while(left <= right) {
            int m = (left + right) / 2;
            if(target > matrix[r][m]) {
                left = m + 1;
            } else if(target < matrix[r][m]) {
                right = m - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        vector<vector<int>> res(row+1, vector<int>(col+1, INT_MAX));
        res[row-1][col] = 0;

        for(int i = row-1; i>=0; i--) {
            for(int j = col-1; j>=0; j--) {
                res[i][j] = grid[i][j] + min(res[i+1][j], res[i][j+1]);
            }
        }

        return res[0][0];
    }
};

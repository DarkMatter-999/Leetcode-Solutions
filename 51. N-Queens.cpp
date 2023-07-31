class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        set<int> cols{};
        set<int> posD{};
        set<int> negD{};

        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res{};

        backtrack(cols, posD, negD, res, board, 0, n);
        return res;
    }

    void backtrack(set<int>& cols, set<int>& posD, set<int>& negD, vector<vector<string>>& res, vector<string>& board, int r, int n) {
        if (r == n) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (cols.find(c) != cols.end() || posD.find(r + c) != posD.end() || negD.find(r - c) != negD.end())
                continue;

            cols.insert(c);
            posD.insert(r + c);
            negD.insert(r - c);
            board[r][c] = 'Q';

            backtrack(cols, posD, negD, res, board, r + 1, n);

            cols.erase(c);
            posD.erase(r + c);
            negD.erase(r - c);
            board[r][c] = '.';
        }
    }
};

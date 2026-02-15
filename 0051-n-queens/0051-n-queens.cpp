class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board) {
        int n = board.size();

        // check left side
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 'Q')
                return false;
        }

        // upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // lower-left diagonal
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void storeSolution(vector<vector<char>>& board,
                       vector<vector<string>>& ans, int n) {
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string row(board[i].begin(), board[i].end());
            temp.push_back(row);
        }
        ans.push_back(temp);
    }

    void solve(vector<vector<char>>& board,
               vector<vector<string>>& ans, int n, int col) {
        if (col == n) {
            storeSolution(board, ans, n);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board)) {
                board[row][col] = 'Q';
                solve(board, ans, n, col + 1);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        solve(board, ans, n, 0);
        return ans;
    }
};

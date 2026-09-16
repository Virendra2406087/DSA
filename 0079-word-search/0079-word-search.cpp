class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word,int i, int j, int index,vector<vector<bool>>& visited) {

        int n = board.size();
        int m = board[0].size();

        if(index == word.size()) {
            return true;
        }

        if(i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }

        if(visited[i][j] == true || board[i][j] != word[index]) {
            return false;
        }

        visited[i][j] = true;

        bool ans = dfs(board, word, i+1, j, index+1, visited) || dfs(board, word, i-1, j, index+1, visited) || dfs(board, word, i, j+1, index+1, visited) || dfs(board, word, i, j-1, index+1, visited);

        visited[i][j] = false;

        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {

                if(board[i][j] == word[0]) {

                    if(dfs(board, word, i, j, 0, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
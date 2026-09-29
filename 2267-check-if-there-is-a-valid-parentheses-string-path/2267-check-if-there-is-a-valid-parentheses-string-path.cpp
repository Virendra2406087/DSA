class Solution { 
public: 
    bool hasValidPath(vector<vector<char>>& grid) { 
        int n = grid.size(); 
        int m = grid[0].size(); 
 
        if (grid[0][0] == ')' || grid[n-1][m-1] == '(') 
            return false; 
 
        // A valid path must have even length
        if ((n + m - 1) % 2 != 0) 
            return false; 
 
        vector<vector<vector<bool>>> dp( 
            n, vector<vector<bool>>(m, vector<bool>(n + m, false)) 
        ); 
 
        dp[0][0][1] = true; 
 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < m; j++) { 
                for (int bal = 0; bal < n + m; bal++) { 
 
                    if (!dp[i][j][bal]) 
                        continue; 
 
                    // Down 
                    if (i + 1 < n) { 
                        if (grid[i + 1][j] == '(') { 
                            dp[i + 1][j][bal + 1] = true; 
                        }  
                        else if (bal > 0) { 
                            dp[i + 1][j][bal - 1] = true; 
                        } 
                    } 
 
                    // Right 
                    if (j + 1 < m) { 
                        if (grid[i][j + 1] == '(') { 
                            dp[i][j + 1][bal + 1] = true; 
                        }  
                        else if (bal > 0) { 
                            dp[i][j + 1][bal - 1] = true; 
                        } 
                    } 
                } 
            } 
        } 
 
        return dp[n - 1][m - 1][0]; 
    } 
};
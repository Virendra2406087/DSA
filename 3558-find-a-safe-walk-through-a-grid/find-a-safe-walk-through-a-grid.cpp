class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        vector<vector<int>> best(m, vector<int>(n, -1));
        queue<tuple<int,int,int>> q;

        q.push({0, 0, startHealth});
        best[0][0] = startHealth;

        vector<pair<int,int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        while (!q.empty()) {
            auto [r, c, h] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1)
                return true;

            for (auto &[dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nr >= m || nc < 0 || nc >= n){
                    continue;
                }

                int nh = h - grid[nr][nc];

                if (nh <= 0){
                    continue;
                }

                if (nh > best[nr][nc]) {
                    best[nr][nc] = nh;
                    q.push({nr, nc, nh});
                }
            }
        }

        return false;
    }
};
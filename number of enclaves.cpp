class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    void dfs(int x, int y, int &m, int &n, vector<vector<bool> >& visited, vector<vector<int> >& grid)
    {
        visited[x][y] = true;

        auto check = [&](int x, int y) {
            return (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && grid[x][y] == 1);
        };

        for (auto &d : dirs)
        {
            if (check(x + d[0], y + d[1])) {
                dfs(x + d[0], y + d[1], m, n, visited, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        vector<vector<bool> > visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            if (!visited[i][0] && grid[i][0] == 1) {
                dfs(i, 0, m, n, visited, grid);
            }

            if (!visited[i][n - 1] && grid[i][n - 1] == 1) {
                dfs(i, n - 1, m, n, visited, grid);
            }
        }

        for (int j = 0; j < n; j++)
        {
            if (!visited[0][j] && grid[0][j] == 1) {
                dfs(0, j, m, n, visited, grid);
            }

            if (!visited[m - 1][j] && grid[m - 1][j] == 1) {
                dfs(m - 1, j, m, n, visited, grid);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

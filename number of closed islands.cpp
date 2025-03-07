class Solution {
public:
    void dfs(int x, int y, int &m, int &n, vector<vector<int> >& grid, vector<vector<int> >& dirs)
    {
        grid[x][y] = 2;

        auto check = [&](int x, int y) {
            return (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0);
        };

        for (auto &d : dirs)
        {
            if (check(x + d[0], y + d[1])) {
                dfs(x + d[0], y + d[1], m, n, grid, dirs);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int islands = 0;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int> > dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 0) {
                dfs(i, 0, m, n, grid, dirs);
            }

            if (grid[i][n - 1] == 0) {
                dfs(i, n - 1, m, n, grid, dirs);
            }
        }

        for (int j = 0; j < n; j++)
        {
            if (grid[0][j] == 0) {
                dfs(0, j, m, n, grid, dirs);
            }

            if (grid[m - 1][j] == 0) {
                dfs(m - 1, j, m, n, grid, dirs);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    dfs(i, j, m, n, grid, dirs);
                    islands++;
                    grid[i][j] = 0;
                }
                else if (grid[i][j] == 2) {
                    grid[i][j] = 0;
                }
            }
        }

        return islands;
    }
};

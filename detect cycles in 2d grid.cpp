class Solution {
public:
    bool dfs(int x, int y, pair<int, int> parent, int &m, int &n, vector<vector<bool> >& visited, vector<vector<char> >& grid, vector<vector<int> >& dirs)
    {
        visited[x][y] = true;

        char curr = grid[x][y];
        bool ans = false;
        int newX = 0, newY = 0;

        auto check = [&](int x, int y) {
            return (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == curr);
        };

        for (auto &d : dirs)
        {
            newX = x + d[0];
            newY = y + d[1];

            if (check(newX, newY))
            {
                if (visited[newX][newY] && parent != make_pair(newX, newY)) {
                    return true;
                }
                else if (!visited[newX][newY])
                {
                    ans = dfs(newX, newY, {x, y}, m, n, visited, grid, dirs);

                    if (ans) {
                        return true;
                    }
                }   
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool> > visited(m, vector<bool>(n, false));
        vector<vector<int> > dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        bool ans = false;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                {
                    ans = dfs(i, j, {-1, -1}, m, n, visited, grid, dirs);

                    if (ans) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

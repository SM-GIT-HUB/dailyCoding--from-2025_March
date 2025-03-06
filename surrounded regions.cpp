class Solution {
public:
    void dfs(int x, int y, int &m, int &n, vector<vector<char> >& b, vector<vector<int> >& dirs)
    {
        b[x][y] = '#';

        auto check = [&](int x, int y) {
            return (x >= 0 && x < m && y >= 0 && y < n && b[x][y] == 'O');
        };

        for (auto &d : dirs)
        {
            if (check(x + d[0], y + d[1])) {
                dfs(x + d[0], y + d[1], m, n, b, dirs);
            }
        }
    }

    void solve(vector<vector<char>>& b) {
        int m = b.size();
        int n = b[0].size();

        vector<vector<int> > dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int i = 0; i < m; i++)
        {
            if (b[i][0] == 'O') {
                dfs(i, 0, m, n, b, dirs);
            }

            if (b[i][n - 1] == 'O') {
                dfs(i, n - 1, m, n, b, dirs);
            }
        }

        for (int j = 0; j < n; j++)
        {
            if (b[0][j] == 'O') {
                dfs(0, j, m, n, b, dirs);
            }
            if (b[m - 1][j] == 'O') {
                dfs(m - 1, j, m, n, b, dirs);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (b[i][j] == '#') {
                    b[i][j] = 'O';
                }
                else if (b[i][j] == 'O') {
                    b[i][j] = 'X';
                }
            }
        }
    }
};

class Solution {
    int dirs[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    
  public:
    void dfs(int x, int y, int m, int n, vector<vector<bool> >& visited, vector<vector<char> >& grid)
    {
        visited[x][y] = true;
        
        auto check = [&](int x, int y) {
            return (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && !visited[x][y]);
        };
        
        for (auto &d : dirs)
        {
            if (check(x + d[0], y + d[1])) {
                dfs(x + d[0], y + d[1], m, n, visited, grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool> > visited(m, vector<bool>(n, 0));
        
        int comp = 0;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    comp++;
                    dfs(i, j, m, n, visited, grid);
                }
            }
        }
        
        return comp;
    }
};

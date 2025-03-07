
// User function Template for C++

class Solution {
    vector<vector<int> > dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  
  public:
    void dfs(int x, int y, int &baseX, int &baseY, int &m, int &n, string &temp, vector<vector<int> >& grid)
    {
        grid[x][y] = -1;
        
        temp += to_string(x - baseX) + "," + to_string(y - baseY) + ".";
        
        auto check = [&](int x, int y) {
            return (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1);
        };
        
        for (auto &d : dirs)
        {
            if (check(x + d[0], y + d[1])) {
                dfs(x + d[0], y + d[1], baseX, baseY, m, n, temp, grid);
            }
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        unordered_set<string> sett;
        
        int m = grid.size();
        int n = grid[0].size();
        
        string temp = "";
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    temp = "";
                    dfs(i, j, i, j, m, n, temp, grid);
                    
                    sett.insert(temp);
                    grid[i][j] = 1;
                }
                else if (grid[i][j] == -1) {
                    grid[i][j] = 1;
                }
            }
        }
        
        return sett.size();
    }
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int> > ans;
        queue<pair<int, int> > q;
        
        for (int i = 0; i < m; i++)
        {
            ans.push_back({});
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    q.push({i, j});
                    ans[i].push_back(0);
                }
                else
                    ans[i].push_back(INT_MAX);
            }
        }
        
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        pair<int, int> curr = {0, 0};
        
        auto check = [&](int x, int y) {
            return (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == INT_MAX);
        };
        
        int x = 0;
        int y = 0;
        
        while (!q.empty())
        {
            curr = q.front();
            q.pop();
            
            x = curr.first;
            y = curr.second;
            
            for (auto &d : dirs)
            {
                if (check(x + d[0], y + d[1]))
                {
                    ans[x + d[0]][y + d[1]] = ans[x][y] + 1;
                    q.push({x + d[0], y + d[1]});
                }
            }
        }
        
        return ans;
    }
};

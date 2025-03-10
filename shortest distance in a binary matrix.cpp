class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<bool> > visited(n, vector<bool>(n, false));
        
        queue<pair<int, int> > q;

        if (grid[0][0] == 0) {
            q.push({0, 0});
        }

        visited[0][0] = true;
        
        int ans = 1;
        int x = 0, y = 0;
        int size = 0;
        
        int dirs[8][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
        
        auto check = [&](int x, int y) {
            return (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y] && grid[x][y] == 0);
        };
        
        while (!q.empty())
        {
            size = q.size();
            
            while (size--)
            {
                x = q.front().first;
                y = q.front().second;
                q.pop();
                
                if (x == n - 1 && y == n - 1) {
                    return ans;
                }
                
                for (auto &d : dirs)
                {
                    if (check(x + d[0], y + d[1]))
                    {
                        visited[x + d[0]][y + d[1]] = true;
                        q.push({x + d[0], y + d[1]});
                    }
                }
            }
            
            ans++;
        }
        
        return -1;
    }
};

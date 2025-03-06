class Solution {
  public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int totalTime = 0;
        int count = 0;
        
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int> > q;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1) {
                    count++;
                }
                else if (mat[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        pair<int, int> curr = {0, 0};
        
        auto check = [&](int x, int y) {
            return (x >= 0 && x < m && y >= 0 && y < n && mat[x][y] == 1);
        };
        
        int x = 0;
        int y = 0;
        
        while (!q.empty() && count)
        {
            int size = q.size();
            
            for (int i = 0; i < size; i++)
            {
                curr = q.front();
                q.pop();
                
                for (auto &d : dirs)
                {
                    x = curr.first + d[0];
                    y = curr.second + d[1];
                    
                    if (check(x, y))
                    {
                        count--;
                        mat[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }
            
            totalTime++;
        }
        
        return count? -1 : totalTime;
    }
};

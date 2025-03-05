class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
        int m = image.size();
        int n = image[0].size();
        
        int color = image[sr][sc];
        image[sr][sc] = newColor;
        
        if (color == newColor) {
            return image;
        }
        
        queue<pair<int, int> > q;
        q.push({sr, sc});
        
        vector<vector<int> > dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        auto isValid = [&](int x, int y) {
            return (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == color);
        };
        
        while (!q.empty())
        {
            pair<int, int> top = q.front();
            q.pop();
            
            int x = top.first;
            int y = top.second;
            
            for (auto &v : dirs)
            {
                if (isValid(x + v[0], y + v[1]))
                {
                    image[x + v[0]][y + v[1]] = newColor;
                    q.push({x + v[0], y + v[1]});
                }
            }
        }
        
        return image;
    }
};

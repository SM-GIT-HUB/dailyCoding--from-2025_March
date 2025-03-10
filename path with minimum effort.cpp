class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int rows = h.size();
        int cols = h[0].size();

        vector<vector<int> > effort(rows, vector<int>(cols, INT_MAX));
        
        effort[0][0] = 0;
        
        priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
        pq.push({0, {0, 0}});
        
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        int eff = 0, x = 0, y = 0;
        
        while (!pq.empty())
        {
            eff = pq.top().first;
            x = pq.top().second.first;
            y = pq.top().second.second;
            pq.pop();

            if (eff > effort[x][y]) {
                continue;
            }
            
            if (x == rows - 1 && y == cols - 1) {
                break;
            }
            
            for (auto &d : dirs)
            {
                int newX = x + d[0];
                int newY = y + d[1];
                
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols)
                {
                    int newEff = max(abs(h[x][y] - h[newX][newY]), eff);
                    
                    if (newEff < effort[newX][newY])
                    {
                        effort[newX][newY] = newEff;
                        pq.push({newEff, {newX, newY}});
                    }
                }
            }
        }
        
        return effort[rows - 1][cols - 1];
    }
};

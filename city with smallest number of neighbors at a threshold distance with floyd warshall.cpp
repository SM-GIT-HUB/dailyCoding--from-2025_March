
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        vector<vector<int> > dist(n, vector<int>(n, INT_MAX));
        
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            
            dist[u][u] = 0, dist[v][v] = 0;
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        
        for (int k = 0; k < n; k++)
        {
            dist[k][k] = 0;
            
            for (int u = 0; u < n; u++)
            {
                dist[u][u] = 0;
                
                for (int v = 0; v < n; v++)
                {
                    dist[v][v] = 0;
                    
                    if (dist[u][k] != INT_MAX && dist[k][v] != INT_MAX) {
                        dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                    }
                }
            }
        }
        
        int ourCity = -1;
        int currCities = INT_MAX;
        
        for (int u = 0; u < n; u++)
        {
            int cities = 0;
            
            for (int v = 0; v < n; v++)
            {
                if (dist[u][v] <= distanceThreshold) {
                    cities++;
                }
            }
            
            if (cities <= currCities)
            {
                currCities = cities;
                ourCity = u;
            }
        }
        
        return ourCity;
    }
};

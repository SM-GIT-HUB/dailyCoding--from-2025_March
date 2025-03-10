
// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int n = adj.size();
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        pq.push({0, src});
        
        pair<int, int> curr = {0, 0};
        int u = 0, d = 0;
        int v = 0, wt = 0;
        
        while (!pq.empty())
        {
            curr = pq.top();
            pq.pop();
            
            u = curr.second;
            d = curr.first;
            
            if (d > dist[u]) {
                continue;
            }
            
            for (auto &p : adj[u])
            {
                v = p.first;
                wt = p.second;
                
                if (d + wt < dist[v])
                {
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist;
    }
};

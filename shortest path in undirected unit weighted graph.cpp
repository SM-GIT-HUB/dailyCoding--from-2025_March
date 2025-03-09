
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
        
        vector<int> dist(n, -1);
        dist[src] = 0;
        
        vector<bool> visited(n, false);
        visited[src] = true;
        
        queue<int> q;
        q.push(src);
        
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u])
            {
                if (!visited[v])
                {
                    dist[v] = dist[u] + 1;
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        
        return dist;
    }
};

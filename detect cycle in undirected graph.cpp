
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int node, vector<vector<int> >& adj, vector<bool>& visited)
    {
        visited[node] = true;
        queue<int> q;
        
        q.push(node);
        int u = 0;
        
        int count = 0;
        
        while (!q.empty())
        {
            u = q.front();
            count = 0;
            q.pop();
            
            for (int v : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
                else
                {
                    count++;
                    
                    if (count > 1) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        
        vector<bool> visited(n, 0);

        bool ans = false;
        
        for (int node = 0; node < n; node++)
        {
            if (!visited[node])
            {
                ans = bfs(node, adj, visited);
                
                if (ans) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

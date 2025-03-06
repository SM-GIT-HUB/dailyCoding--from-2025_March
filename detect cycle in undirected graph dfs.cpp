
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int parent, int u, vector<bool>& visited, vector<vector<int> >& adj)
    {
        visited[u] = true;
        bool ans = false;
        
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                ans = dfs(u, v, visited, adj);
                
                if (ans) {
                    return true;
                }
            }
            else if (v != parent) {
                return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        
        vector<bool> visited(n, false);
        bool ans = false;
        
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ans = dfs(-1, i, visited, adj);
                
                if (ans) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

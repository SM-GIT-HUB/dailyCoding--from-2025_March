class Solution {
  public:
    void dfs(int u, vector<bool>& visited, vector<vector<int> >& adj, int n)
    {
        visited[u] = true;
        
        for (int v = 0; v < n; v++)
        { 
            if (u != v && !visited[v] && adj[u][v] == 1) {
                dfs(v, visited, adj, n);
            }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<bool> visited(V);
        int comp = 0;
        
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                comp++;
                dfs(i, visited, adj, V);
            }
        }
        
        return comp;
    }
};

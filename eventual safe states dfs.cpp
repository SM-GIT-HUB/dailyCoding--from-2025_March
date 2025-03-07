
// User function Template for C++

class Solution {
  public:
    bool dfs(int u, vector<int>& visited, vector<int> *adj)
    {
        visited[u] = 2;
        bool flag = 0;
        
        for (int v : adj[u])
        {
            if (!visited[v] && dfs(v, visited, adj) == true) {
                flag = 1;
            }
            else if (visited[v] == 2) {
                flag = 1;
            }
        }
        
        if (flag) {
            return true;
        }
        else
        {
            visited[u] = 1;
            return false;
        }
        
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V, 0);
        vector<int> ans;
        
        for (int u = 0; u < V; u++)
        {
            if (!visited[u]) {
                dfs(u, visited, adj);
            }
        }
        
        for (int node = 0; node < V; node++)
        {
            if (visited[node] == 1) {
                ans.push_back(node);
            }
        }
        
        return ans;
    }
};

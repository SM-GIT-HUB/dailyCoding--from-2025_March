
class Solution {
  public:
    void dfs(int u, vector<bool>& visited, vector<int>& ans, vector<vector<int> >& adj)
    {
        visited[u] = true;
        
        for (int v : adj[u])
        {
            if (!visited[v]) {
                dfs(v, visited, ans, adj);
            }
        }
        
        ans.push_back(u);
    }
  
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int n = adj.size();
        
        vector<int> ans;
        vector<bool> visited(n, false);
        
        for (int u = 0; u < n; u++)
        {
            if (!visited[u]) {
                dfs(u, visited, ans, adj);
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

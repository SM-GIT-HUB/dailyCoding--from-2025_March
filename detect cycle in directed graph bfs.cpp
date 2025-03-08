
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        // code here
        int ans = 0;
        int n = adj.size();
        
        vector<int> inDegree(n, 0);
        
        for (int u = 0; u < n; u++)
        {
            for (int v : adj[u])
            {
                inDegree[v]++;
            }
        }
        
        queue<int> q;
        
        for (int u = 0; u < n; u++)
        {
            if (inDegree[u] == 0) {
                q.push(u);
            }
        }
        
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u])
            {
                inDegree[v]--;
                
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
            
            ans++;
        }
        
        return (ans != n);
    }
};

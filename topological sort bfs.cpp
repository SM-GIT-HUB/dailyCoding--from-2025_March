
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int n = adj.size();
        
        vector<int> ans;
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
            
            ans.push_back(u);
            
            for (int v : adj[u])
            {
                inDegree[v]--;
                
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return ans;
    }
};

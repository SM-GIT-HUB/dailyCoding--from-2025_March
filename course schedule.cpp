class Solution {
public:
    bool dfs(int u, vector<int>& visited, vector<vector<int> >& adj)
    {
        visited[u] = 2;
        
        for (int v : adj[u])
        {
            if (!visited[v] && dfs(v, visited, adj) == true) {
                return true;
            }
            else if (visited[v] == 2) {
                return true;
            }
        }
        
        visited[u] = 1;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int> > adj(n);
        
        vector<int> visited(n, 0);
        
        for (auto &v : pre)
        {
            adj[v[1]].push_back(v[0]);
        }
        
        for (int u = 0; u < n; u++)
        {
            if (!visited[u] && dfs(u, visited, adj) == true) {
                return false;
            }
        }
        
        return true;
    }
};

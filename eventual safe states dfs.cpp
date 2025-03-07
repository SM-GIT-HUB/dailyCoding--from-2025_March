class Solution {
public:
    bool dfs(int u, vector<int>& visited, vector<int>& ans, vector<vector<int> >& adj)
    {
        visited[u] = 2;
        bool flag = 0;
        
        for (int v : adj[u])
        {
            if (!visited[v] && dfs(v, visited, ans, adj) == true) {
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
            ans.push_back(u);
            return false;
        }
    }

    vector<int> eventualSafeNodes(vector<vector<int> >& adj) {
        int V = adj.size();

        vector<int> visited(V, 0);
        vector<int> ans;
        
        for (int u = 0; u < V; u++)
        {
            if (!visited[u]) {
                dfs(u, visited, ans, adj);
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

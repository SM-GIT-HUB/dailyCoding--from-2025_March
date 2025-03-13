class Solution {
public:
    void dfs(int node, vector<bool>& visited, int &size, int &count, vector<vector<int> >& adj)
    {
        visited[node] = true;
        size++;

        for (int adjNode : adj[node])
        {
            if (!visited[adjNode]) {
                dfs(adjNode, visited, size, count, adj);
            }
            count++;
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int> > adj(n);
        vector<bool> visited(n, false);

        for (auto &e : edges)
        {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int u = 0; u < n; u++)
        {
            if (!visited[u])
            {
                int size = 0, edgeCount = 0;
                dfs(u, visited, size, edgeCount, adj);

                if (edgeCount == (size * (size - 1))) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

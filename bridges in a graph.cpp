class Solution {
public:
    void dfs(int node, int parent, int &timer, vector<bool>& visited, vector<int>& low, vector<int>& time, vector<vector<int> >& adj, vector<vector<int> >& ans)
    {
        low[node] = timer;
        time[node] = timer++;
        visited[node] = true;

        for (int adjNode : adj[node])
        {
            if (!visited[adjNode])
            {
                dfs(adjNode, node, timer, visited, low, time, adj, ans);
                low[node] = min(low[node], low[adjNode]);

                if (low[adjNode] > time[node]) {
                    ans.push_back({node, adjNode});
                }
            }
            else if (adjNode != parent) {
                low[node] = min(low[node], time[adjNode]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int> > ans;
        vector<vector<int> > adj(n);
        vector<int> low(n, 0);
        vector<int> time(n, 0);
        vector<bool> visited(n, false);

        for (auto &c : connections)
        {
            int u = c[0], v = c[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int timer = 0;
        dfs(0, -1, timer, visited, low, time, adj, ans);

        return ans;
    }
};

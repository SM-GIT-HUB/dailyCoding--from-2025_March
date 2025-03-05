void dfs(int u, vector<int>& temp, vector<bool>& visited, vector<vector<int> >& adj)
{
    visited[u] = true;
    temp.push_back(u);

    for (int v : adj[u])
    {
        if (!visited[v]) {
            dfs(v, temp, visited, adj);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int> > adj(V);

    for (auto &e : edges)
    {
        int u = e[0];
        int v = e[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int> > ans;
    vector<bool> visited(V, 0);

    for (int u = 0; u < V; u++)
    {
        vector<int> temp;

        if (!visited[u])
        {
            dfs(u, temp, visited, adj);
            ans.push_back(temp);
        }
    }

    return ans;
}

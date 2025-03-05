vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    vector<int> ans;

    queue<int> q;
    vector<bool> visited(n, 0);

    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        ans.push_back(u);

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return ans;
}

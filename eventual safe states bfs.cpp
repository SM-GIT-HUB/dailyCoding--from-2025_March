class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int> > adj(n);
        vector<int> inDegree(n, 0);

        for (int u = 0; u < n; u++)
        {
            for (int v : graph[u])
            {
                adj[v].push_back(u);
                inDegree[u]++;
            }
        }

        queue<int> q;
        vector<int> ans;

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
        }

        for (int u = 0; u < n; u++)
        {
            if (inDegree[u] == 0) {
                ans.push_back(u);
            }
        }
        
        return ans;
    }
};

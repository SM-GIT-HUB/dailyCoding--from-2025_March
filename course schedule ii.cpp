class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> ans;

        vector<vector<int> > adj(n);
        vector<int> inDegree(n, 0);

        for (auto &v : pre)
        {
            adj[v[1]].push_back(v[0]);
            inDegree[v[0]]++;
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

            ans.push_back(u);
        }

        if (ans.size() != n) {
            return {};
        }

        return ans;
    }
};

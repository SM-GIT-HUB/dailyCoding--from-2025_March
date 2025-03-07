class Solution {
public:
    bool dfs(int node, int c, vector<int>& color, vector<vector<int> >& adj)
    {
        color[node] = c;

        bool ans = true;

        for (int v : adj[node])
        {
            if (color[v] == -1)
            {
                ans = dfs(v, !c, color, adj);

                if (!ans) {
                    return false;
                }
            }
            else if (color[v] == c) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        
        vector<int> color(n, -1);
        bool ans = true;
        
        for (int node = 0; node < n; node++)
        {
            if (color[node] == -1)
            {
                ans = dfs(node, 0, color, adj);

                if (!ans) {
                    return false;
                }
            }
        }

        return true;
    }
};

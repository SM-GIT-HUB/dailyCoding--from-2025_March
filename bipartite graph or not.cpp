class Solution {
public:
    bool bfs(int node, vector<int>& color, vector<vector<int> >& adj)
    {
        queue<int> q;
        color[node] = 0;
        
        q.push(node);
        int c = 0;
        int u = 0;
        
        while (!q.empty())
        {
            u = q.front();
            q.pop();
            
            c = color[u];
            
            for (int v : adj[u])
            {
                if (color[v] == c) {
                    return false;
                }
                else if (color[v] == -1)
                {
                    color[v] = !c;
                    q.push(v);
                }
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
                ans = bfs(node, color, adj);

                if (!ans) {
                    return false;
                }
            }
        }

        return true;
    }
};

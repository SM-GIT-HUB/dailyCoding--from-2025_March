
//Position this line where user code will be pasted.
class Solution {
  public:
    void dfs1(int node, vector<bool>& visited, vector<int>& stack, vector<vector<int> >& adj)
    {
        visited[node] = true;
        
        for (int adjNode : adj[node])
        {
            if (!visited[adjNode]) {
                dfs1(adjNode, visited, stack, adj);
            }
        }
        
        stack.push_back(node);
    }
    
    void dfs2(int node, vector<bool>& visited, vector<vector<int> >& adjTs)
    {
        visited[node] = true;
        
        for (int adjNode : adjTs[node])
        {
            if (!visited[adjNode]) {
                dfs2(adjNode, visited, adjTs);
            }
        }
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<vector<int> > adjTs(n);
        vector<int> stack;
        
        vector<bool> visited(n, false);
        
        for (int u = 0; u < n; u++)
        {
            if (!visited[u]) {
                dfs1(u, visited, stack, adj);
            }
            
            for (int v : adj[u])
            {
                adjTs[v].push_back(u);
            }
        }
        
        fill(visited.begin(), visited.end(), false);
        
        int comp = 0;
        
        while (!stack.empty())
        {
            int node = stack.back();
            stack.pop_back();
            
            if (!visited[node])
            {
                dfs2(node, visited, adjTs);
                comp++;
            }
        }
        
        return comp;
    }
};

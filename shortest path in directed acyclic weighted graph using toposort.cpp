

// User function Template for C++
class Solution {
  public:
    void dfs(int u, vector<bool>& visited, vector<int>& topo, vector<vector<pair<int, int> > >& adj)
    {
        visited[u] = true;
        
        for (auto &v : adj[u])
        {
            if (!visited[v.first]) {
                dfs(v.first, visited, topo, adj);
            }
        }
        
        topo.push_back(u);
    }
  
    void topoSort(int n, vector<int>& topo, vector<vector<pair<int, int> > >& adj)
    {
        vector<bool> visited(n, false);
        dfs(0, visited, topo, adj);
    }
    
    
    void fixDistance(vector<int>& topo, vector<vector<pair<int, int> > >& adj, vector<int>& dist)
    {
        while (!topo.empty())
        {
            int u = topo.back();
            topo.pop_back();
            
            for (auto &p : adj[u])
            {
                int v = p.first;
                int w = p.second;
                
                if (dist[v] == -1 || dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
    
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int> > > adj(V);
        
        for (auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
        }
        
        vector<int> topo;
        topoSort(V, topo, adj);
        
        vector<int> dist(V, -1);
        dist[0] = 0;
        
        fixDistance(topo, adj, dist);
        
        return dist;
    }
};



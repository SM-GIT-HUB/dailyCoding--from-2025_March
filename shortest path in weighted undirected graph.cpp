
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int, int> > > adj(n + 1);
        
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> dist(n + 1, INT_MAX);
        vector<int> parent(n + 1, -1);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        
        pq.push({0, 1});
        dist[1] = 0;
        
        while (!pq.empty())
        {
            int currNode = pq.top().second;
            int currDist = pq.top().first;
            pq.pop();
            
            if (currDist > dist[currNode]) {
                continue;
            }
            
            if (currNode == n) {
                continue;
            }
            
            for (auto &p : adj[currNode])
            {
                int adjNode = p.first;
                int wt = p.second;
                
                if (currDist + wt < dist[adjNode])
                {
                    parent[adjNode] = currNode;
                    dist[adjNode] = currDist + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        if (dist[n] == INT_MAX) {
            return {-1};
        }
        
        vector<int> ans;

        for (int node = n; node != -1; node = parent[node])
        {
            ans.push_back(node);
        }
        
        ans.push_back(dist[n]);
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

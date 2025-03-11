
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        int flag = 0;
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        for (int i = 0; i < V; i++)
        {
            flag = 0;
            
            for (auto &e : edges)
            {
                int u = e[0];
                int v = e[1];
                int wt = e[2];
                
                if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                {
                    flag = 1;
                    dist[v] = dist[u] + wt;
                }
            }
            
            if (flag == 0) {
                break;
            }
        }
        
        if (flag) {
            return {-1};
        }
        else
            return dist;
    }
};

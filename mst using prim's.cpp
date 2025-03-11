
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<bool> mst(V, 0);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        
        pq.push({0, 0});
        int sum = 0;
        
        while (!pq.empty())
        {
            int currNode = pq.top().second;
            int w = pq.top().first;
            pq.pop();
            
            if (mst[currNode]) {
                continue;
            }
            
            mst[currNode] = true;
            sum += w;
            
            for (auto &v : adj[currNode])
            {
                int adjNode = v[0];
                int wt = v[1];
                
                if (!mst[adjNode]) {
                    pq.push({wt, adjNode});
                }
            }
        }
        
        return sum;
    }
};

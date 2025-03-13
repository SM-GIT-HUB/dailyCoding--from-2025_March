
//User function Template for C++

class Solution {
  public:
    void dfs(int node, int parent, int timer, vector<int>& disc, vector<int>& low, vector<bool>& visited, vector<int>& ans, vector<int> adj[])
    {
        disc[node] = low[node] = timer++;
        visited[node] = true;
        bool included = false;
        int children = 0;
        
        for (int adjNode: adj[node])
        {
            if (node == adjNode || adjNode == parent) {
                continue;
            }
            
            if (!visited[adjNode])
            {
                children++;
                
                dfs(adjNode, node, timer, disc, low, visited, ans, adj);
                low[node] = min(low[node], low[adjNode]);
                
                if (parent != -1 && low[adjNode] >= disc[node] && !included)
                {
                    ans.push_back(node);
                    included = true;
                }
            }
            else
                low[node] = min(low[node], disc[adjNode]);
        }
        
        if (parent == -1 && children > 1) {
            ans.push_back(node);
        }
    }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> ans;
        vector<bool> visited(V, false);
        vector<int> low(V, -1);
        vector<int> disc(V, -1);
        
        int timer = 0;
        dfs(0, -1, timer, disc, low, visited, ans, adj);
        
        sort(ans.begin(), ans.end());
        
        if (ans.size() == 0) {
            return {-1};
        }
        
        return ans;
    }
};

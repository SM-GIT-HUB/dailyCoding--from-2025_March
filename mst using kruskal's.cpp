
class DSUrank {
public:
	vector<int> rank, parent;
	
	DSUrank(int n)
	{
		rank.resize(n + 1, 0);
		parent.resize(n + 1);
		
		for (int i = 0; i <= n; i++)
		{
			parent[i] = i;
		}
	}
	
	int findUltParent(int node)
	{
		if (parent[node] == node) {
			return node;
		}
		
		return parent[node] = findUltParent(parent[node]);
	}
	
	void unionByRank(int u, int v)
	{
		int uParent = findUltParent(u);
		int vParent = findUltParent(v);
		
		if (uParent == vParent) {
			return;
		}
		else if (rank[uParent] > rank[vParent]) {
			parent[vParent] = uParent;
		}
		else if (rank[uParent] < rank[vParent]) {
			parent[uParent] = vParent;
		}
		else
		{
			parent[vParent] = uParent;
			rank[uParent]++;
		}
	}
	
	bool sameComp(int u, int v)
	{
		if (findUltParent(u) == findUltParent(v)) {
			return true;
		}
		
		return false;
	}
};

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<pair<int, pair<int, int> > > edges;
        
        for (int node = 0; node < V; node++)
        {
            for (auto &vec : adj[node])
            {
                int adjNode = vec[0];
                int wt = vec[1];
                
                edges.push_back({wt, {node, adjNode}});
            }
        }
        
        sort(edges.begin(), edges.end());
        
        DSUrank ds(V);
        int sum = 0;
        
        for (auto &e : edges)
        {
            int wt = e.first;
            int u = e.second.first;
            int v = e.second.second;
            
            if (!ds.sameComp(u, v))
            {
                sum += wt;
                ds.unionByRank(u, v);
            }
        }
        
        return sum;
    }
};

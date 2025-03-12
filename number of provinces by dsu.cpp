
//User function Template for C++
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
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        DSUrank ds(V);
        
        for (int u = 0; u < V; u++)
        {
            for (int v = 0; v < V; v++)
            {
                if (adj[u][v]) {
                    ds.unionByRank(u, v);
                }
            }
        }
        
        int comp = 0;
        
        for (int node = 0; node < V; node++)
        {
            if (ds.findUltParent(node) == node) {
                comp++;
            }
        }
        
        return comp;
    }
};

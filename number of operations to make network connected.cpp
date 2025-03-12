class DSUrank {
public:
	vector<int> rank, parent;
    int comp;
	
	DSUrank(int n)
	{
        comp = n;
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

        comp--;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extra = 0;
        DSUrank ds(n);

        for (auto &e : connections)
        {
            int u = e[0], v = e[1];

            if (ds.sameComp(u, v)) {
                extra++;
            }
            else
                ds.unionByRank(u, v);
        }

        int comp = ds.comp;

        if (extra >= (comp - 1)) {
            return (comp - 1);
        }
        else
            return -1;
    }
};

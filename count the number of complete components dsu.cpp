class DSUsize {
public:
	vector<int> size, parent, edgeCount;
	
	DSUsize(int n)
	{
		for (int i = 0; i <= n; i++)
		{
            size.push_back(1);
            edgeCount.push_back(0);
			parent.push_back(i);
		}
	}
	
	int findUltParent(int node)
	{
		if (parent[node] == node) {
			return node;
		}
		
		return parent[node] = findUltParent(parent[node]);
	}
	
	void unionBySize(int u, int v)
	{
		int uParent = findUltParent(u);
		int vParent = findUltParent(v);
		
		if (uParent == vParent)
        {
            edgeCount[uParent]++;
			return;
		}
		else if (size[uParent] >= size[vParent])
		{
			parent[vParent] = uParent;
			size[uParent] += size[vParent];
            edgeCount[uParent] += 1 + edgeCount[vParent];
		}
		else
		{
			parent[uParent] = vParent;
			size[vParent] += size[uParent];
            edgeCount[vParent] += 1 + edgeCount[uParent];
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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSUsize ds(n);
        int u = 0, v = 0, parent = 0;

        for (auto &e : edges)
        {
            u = e[0], v = e[1];
            ds.unionBySize(u, v);
        }

        int ans = 0;
        int size = 0;

        for (int node = 0; node < n; node++)
        {
            parent = ds.findUltParent(node);

            if (parent == node)
            {
                size = ds.size[parent];

                if (ds.edgeCount[parent] == (size * (size - 1) / 2)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

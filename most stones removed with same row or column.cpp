class DSUsize {
public:
	vector<int> size, parent;
	
	DSUsize(int n)
	{
		size.resize(n + 1, 1);
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
	
	void unionBySize(int u, int v)
	{
		int uParent = findUltParent(u);
		int vParent = findUltParent(v);
		
		if (uParent == vParent) {
			return;
		}
		else if (size[uParent] >= size[vParent])
		{
			parent[vParent] = uParent;
			size[uParent] += size[vParent];
		}
		else
		{
			parent[uParent] = vParent;
			size[vParent] += size[uParent];
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
    int removeStones(vector<vector<int>>& stones) {
        int m = 0, n = 0;

        for (auto &s : stones)
        {
            m = max(s[0], m);
            n = max(s[1], n);
        }

        m++, n++;
        DSUsize ds(m + n);
        unordered_map<int, bool> mapp;

        for (auto &s : stones)
        {
            int row = s[0];
            int col = s[1];

            ds.unionBySize(row, m + col);
            mapp[row] = true;
            mapp[m + col] = true;
        }

        int total = 0;

        for (auto &it : mapp)
        {
            if (ds.findUltParent(it.first) == it.first) {
                total++;
            }
        }

        return (stones.size() - total);
    }
};

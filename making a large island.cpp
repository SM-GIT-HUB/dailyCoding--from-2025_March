class DSUsize {
public:
	vector<int> size, parent;
	
	DSUsize(int n)
	{
		for (int i = 0; i <= n; i++)
		{
			size.push_back(1);
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSUsize ds(n * n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0) {
                    continue;
                }

                int node = n * i + j;

                if (j + 1 < n && grid[i][j + 1] == 1)
                {
                    int adjNode = n * i + (j + 1);
                    ds.unionBySize(node, adjNode);
                }

                if (i + 1 < n && grid[i + 1][j] == 1)
                {
                    int adjNode = n * (i + 1) + j;
                    ds.unionBySize(node, adjNode);
                }
            }
        }

        int ans = ds.size[ds.findUltParent(0)];

        auto check = [&](int x, int y) {
            return (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1);
        };

        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1) {
                    continue;
                }

                int node = n * i + j;
                int size = 1;
                set<int> sett;

                for (auto &d : dirs)
                {
                    int nRow = i + d[0];
                    int nCol = j + d[1];
                    int adjNode = nRow * n + nCol;

                    if (check(nRow, nCol))
                    {
                        int parentNode = ds.findUltParent(adjNode);

                        if (!sett.count(parentNode))
                        {
                            size += ds.size[parentNode];
                            sett.insert(parentNode);
                        }
                    }
                }

                ans = max(size, ans);
            }
        }

        return ans;
    }
};

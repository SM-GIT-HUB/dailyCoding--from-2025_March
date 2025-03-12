
// User function Template for C++

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
    vector<int> numOfIslands(int m, int n, vector<vector<int>> &operators) {
        // code here
        vector<int> ans;
        DSUrank ds(m * n);
        vector<vector<bool> > mat(m, vector<bool>(n, false));
        
        int comp = 0;
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        auto check = [&](int x, int y) {
            return (x >= 0 && x < m && y >= 0 && y < n && mat[x][y] == true);
        };
        
        for (auto &ops : operators)
        {
            int x = ops[0];
            int y = ops[1];
            int currNode = n * x + y;
            
            if (mat[x][y])
            {
                ans.push_back(comp);
                continue;
            }
            
            mat[x][y] = true;
            comp++;
            
            for (auto &d : dirs)
            {
                int adjNode = n * (x + d[0]) + (y + d[1]);
                
                if (check(x + d[0], y + d[1]) && !ds.sameComp(currNode, adjNode))
                {
                    comp--;
                    ds.unionByRank(currNode, adjNode);
                }
            }
            
            ans.push_back(comp);
        }
        
        return ans;
    }
};

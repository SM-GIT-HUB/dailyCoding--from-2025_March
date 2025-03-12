
// User function Template for C++

class DSUrank {
public:
	vector<vector<int> > rank;
	vector<vector<pair<int, int> > > parent;
	
	DSUrank(int m, int n)
	{
		rank.resize(m);
		parent.resize(m);
		
		for (int i = 0; i < m; i++)
		{
		    for (int j = 0; j < n; j++)
		    {
		        rank[i].push_back(0);
		        parent[i].push_back({i, j});
		    }
		}
	}
	
	pair<int, int> findUltParent(pair<int, int> node)
	{
		if (parent[node.first][node.second] == node) {
			return node;
		}
		
		return parent[node.first][node.second] = findUltParent(parent[node.first][node.second]);
	}
	
	void unionByRank(pair<int, int> u, pair<int, int> v)
	{
		pair<int, int> uParent = findUltParent(u);
		pair<int, int> vParent = findUltParent(v);
		
		if (uParent == vParent) {
			return;
		}
		else if (rank[uParent.first][uParent.second] > rank[vParent.first][vParent.second]) {
			parent[vParent.first][vParent.second] = uParent;
		}
		else if (rank[uParent.first][uParent.second] < rank[vParent.first][vParent.second]) {
			parent[uParent.first][uParent.second] = vParent;
		}
		else
		{
			parent[vParent.first][vParent.second] = uParent;
			rank[uParent.first][uParent.second]++;
		}
	}
	
	bool sameComp(pair<int, int> u, pair<int, int> v)
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
        DSUrank ds(m, n);
        
        vector<vector<int> > mat(m, vector<int>(n, 0));
        
        vector<int> ans;
        int comp = 0;
        
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        for (auto &op : operators)
        {
            int x = op[0];
            int y = op[1];
            
            if (mat[x][y] == 1)
            {
                ans.push_back(comp);
                continue;
            }
            
            comp++;
            
            mat[x][y] = 1;
            
            for (auto &d : dirs)
            {
                int newX = x + d[0], newY = y + d[1];
                
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && mat[newX][newY] == 1)
                {
                    if (!ds.sameComp({x, y}, {newX, newY}))
                    {
                        ds.unionByRank({x, y}, {newX, newY});
                        comp--;
                    }
                }
            }
            
            ans.push_back(comp);
        }
        
        return ans;
    }
};

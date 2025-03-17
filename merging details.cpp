
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
    vector<vector<string>> mergeDetails(vector<vector<string>>& acc) {
        // code here
        int n = acc.size();
        unordered_map<string, int> ownedBy;
        vector<vector<string> > mergedMails;

        DSUrank ds(n);

        for (int i = 0; i < n; i++)
        {
            int len = acc[i].size();
            mergedMails.push_back({""});

            for (int j = 1; j < len; j++)
            {
                string curr = acc[i][j];

                if (ownedBy.count(curr)) {
                    ds.unionByRank(ownedBy[curr], i);
                }
                else
                    ownedBy[curr] = i;
            }
        }

        for (auto &it : ownedBy)
        {
            string curr = it.first;
            int parent = ds.findUltParent(it.second);

            mergedMails[parent].push_back(curr);
        }

        vector<vector<string> > ans;
        int parent = n;

        while (!mergedMails.empty())
        {
            parent--;
            if (mergedMails.back().size() == 1)
            {
                mergedMails.pop_back();
                continue;
            }

            sort(mergedMails.back().begin(), mergedMails.back().end());
            mergedMails.back()[0] = acc[parent][0];
            
            ans.push_back(mergedMails.back());
            mergedMails.pop_back();
        }

        return ans;
    }
};

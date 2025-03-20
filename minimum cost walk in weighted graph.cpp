class DSUrank {
public:
	vector<int> rank, parent;
    vector<int> AND;
	
	DSUrank(int n)
	{
		rank.resize(n + 1, 0);
		parent.resize(n + 1);
        AND.resize(n + 1, INT_MAX);
		
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
	
	void unionByRank(int u, int v, int w)
	{
		int uParent = findUltParent(u);
		int vParent = findUltParent(v);
		
		if (uParent == vParent)
        {
            AND[uParent] = (AND[uParent] & w);
			return;
		}
		else if (rank[uParent] > rank[vParent])
        {
			parent[vParent] = uParent;
            AND[uParent] = (AND[uParent] & AND[vParent] & w);
		}
		else if (rank[uParent] < rank[vParent])
        {
			parent[uParent] = vParent;
            AND[vParent] = (AND[vParent] & AND[uParent] & w);
		}
		else
		{
			parent[vParent] = uParent;
			rank[uParent]++;
            AND[uParent] = (AND[uParent] & AND[vParent] & w);
		}
	}
	
	bool sameComp(int u, int v)
	{
		return (findUltParent(u) == findUltParent(v));
	}
};

class Solution {
public:
    void dijkstra(int u, vector<int>& dist, vector<vector<pair<int, int> > >& adj)
    {
        priority_queue<pair<int, int> > pq;
        pq.push({INT_MAX, u});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();

            if (cost > dist[node]) {
                continue;
            }

            for (auto &v : adj[node])
            {
                int adjNode = v.first;
                int c = v.second;

                if ((cost & c) < dist[adjNode])
                {
                    dist[adjNode] = (cost & c);
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSUrank ds(n);

        for (auto &e : edges)
        {
            ds.unionByRank(e[0], e[1], e[2]);
        }

        vector<int> ans;
        
        for (auto &q : query)
        {
            int u = q[0], v = q[1];

            if (!ds.sameComp(u, v)) {
                ans.push_back(-1);
            }
            else
                ans.push_back(ds.AND[ds.findUltParent(u)]);
        }

        return ans;
    }
};

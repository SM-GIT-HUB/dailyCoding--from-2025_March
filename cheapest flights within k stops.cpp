class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int> > > adj(n);

        for (auto &f : flights)
        {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> minPrice(n, INT_MAX);
        queue<pair<int, int> > q;

        q.push({0, src});
        minPrice[src] = 0;
        int stops = 0;

        while (!q.empty())
        {
            int size = q.size();

            while (size--)
            {
                int city = q.front().second;
                int currPrice = q.front().first;
                q.pop();

                for (auto &v : adj[city])
                {
                    int nextCity = v.first;
                    int price = v.second;

                    if (currPrice + price < minPrice[nextCity])
                    {
                        minPrice[nextCity] = currPrice + price;
                        q.push({minPrice[nextCity], nextCity});
                    }
                }
            }

            stops++;

            if (stops > k) {
                break;
            }
        }

        return (minPrice[dst] == INT_MAX)? -1 : minPrice[dst];
    }
};

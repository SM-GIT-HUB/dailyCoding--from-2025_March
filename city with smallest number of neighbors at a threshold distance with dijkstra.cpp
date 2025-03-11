class Solution {
public:
    void dijkstra(int src, vector<vector<pair<int, int> > >& adj, vector<vector<int> >& dist)
    {
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        pq.push({0, src});
        dist[src][src] = 0;

        while (!pq.empty())
        {
            int currNode = pq.top().second;
            int currDist = pq.top().first;
            pq.pop();

            if (currDist > dist[src][currNode]) {
                continue;
            }

            for (auto &v : adj[currNode])
            {
                int adjNode = v.first;
                int newDistance = currDist + v.second;

                if (newDistance < dist[src][adjNode])
                {
                    dist[src][adjNode] = newDistance;
                    pq.push({dist[src][adjNode], adjNode});
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int> > dist(n, vector<int>(n, INT_MAX));

        vector<vector<pair<int, int> > > adj(n);

        for (auto &e : edges)
        {
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        for (int u = 0; u < n; u++)
        {
            dijkstra(u, adj, dist);
        }

        int ourCity = -1;
        int minCities = INT_MAX;

        for (int u = 0; u < n; u++)
        {
            int cities = 0;

            for (int v = 0; v < n; v++)
            {
                if (dist[u][v] <= distanceThreshold) {
                    cities++;
                }
            }

            if (cities <= minCities)
            {
                minCities = cities;
                ourCity = u;
            }
        }

        return ourCity;
    }
};

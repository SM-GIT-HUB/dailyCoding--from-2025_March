class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long> > > adj(n);
        long long mod = 1e9 + 7;

        for (auto &vec : roads)
        {
            int u = vec[0], v = vec[1], w = vec[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> minTime(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;

        pq.push({0, 0});
        minTime[0] = 0;
        ways[0] = 1;

        long long ans = 0;

        while (!pq.empty())
        {
            int currNode = pq.top().second;
            long long currTime = pq.top().first;
            pq.pop();

            if (currTime > minTime[currNode]) {
                continue;
            }

            for (auto &p : adj[currNode])
            {
                int adjNode = p.first;
                long long time = p.second;

                if (currTime + time < minTime[adjNode])
                {
                    ways[adjNode] = ways[currNode];
                    minTime[adjNode] = currTime + time;
                    pq.push({minTime[adjNode], adjNode});
                }
                else if (currTime + time == minTime[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[currNode]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};

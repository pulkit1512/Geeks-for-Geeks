class Solution {
  public:
      int countPaths(int V, vector<vector<int>>& edges) {
          vector<vector<pair<int, int>>> adj(V);
          for (int i = 0; i < edges.size(); i++) {
              int u = edges[i][0];
              int v = edges[i][1];
              int w = edges[i][2];
              adj[u].push_back({v, w});
              adj[v].push_back({u, w});
          }

          priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
          vector<long long> dist(V, 1e18);
          vector<long long> ways(V, 0);

          dist[0] = 0;
          ways[0] = 1;
          pq.push({0, 0});

         

          while (!pq.empty()) {
              long long dis = pq.top().first;
              int u = pq.top().second;
              pq.pop();

              if (dis > dist[u]) continue;

              for (auto it : adj[u]) {
                  int v = it.first;
                  long long wt = it.second;

                  if (dis + wt < dist[v]) {
                      dist[v] = dis + wt;
                      ways[v] = ways[u];
                      pq.push({dist[v], v});
                  }
                  else if (dis + wt == dist[v]) {
                      ways[v] = (ways[v] + ways[u]) ;
                  }
              }
          }

          return ways[V - 1];
      }
  };
#include <iostream>
#include <vector>

using namespace std;

vector<int> bellman_ford (int n, vector<vector<pair<int, int>>>& adj, int s) {
  vector<int> d(n, 1e9);
  d[s] = 0;
  for (int i = 0; i < n; i++) {
    bool upd = false;
    for (int u = 0; u < n; u++) {
      for (auto e : adj[u]) {
        int v = e.first;
        int weight = e.second;
        if (d[u] + weight < d[v]) {
          d[v] = d[u] + weight;
          upd = true;
        }
      }
    }
    if (!upd) {
      break;
    }
  }
  return d;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, q, start;
  cin >> n >> m >> q >> start;
  start--;
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    adj[a].emplace_back(b, w);
    adj[b].emplace_back(a, w);
  }
  vector<int> req;
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    x--;
    req.emplace_back(x);
  }
  vector<int> d = bellman_ford(n, adj, start);
  for (int i = 0; i < q; i++) {
    if (d[req[i]] != 1e9) {
      cout << d[req[i]] << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
}
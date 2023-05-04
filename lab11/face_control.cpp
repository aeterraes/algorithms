#include <iostream>
#include <vector>

using namespace std;

bool bellman_ford (int n, vector<vector<pair<int, int>>>& adj) {
  vector<int> d(n, 1e9);
  d[0] = 0;
  for (int i = 0; i < n - 1; i++) {
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
      return false;
    }
  }
  for (int u = 0; u < n; u++) {
    for (auto e : adj[u]) {
      int v = e.first;
      int weight = e.second;
      if (d[u] + weight < d[v]) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, N, k;
  cin >> N >> k;
  for (int p = 0; p < N; p++) {
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
      int a, b, w;
      cin >> a >> b >> w;
      a--;
      b--;
      adj[a].emplace_back(b, w);
    }
    bool ok = bellman_ford(n, adj);
    if (ok) {
      if (k <= 1) {
        cout << "NO" << '\n';
      } else {
        cout << "YES" << '\n';
      }
    } else {
      cout << "YES" << '\n';
    }
  }
  return 0;
}
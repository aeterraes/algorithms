#include <iostream>
#include <vector>

using namespace std;

struct edge {
  int v, w, f;
  edge(int v, int w) : v(v), w(w), f(0) {}
};

int dfs(vector<edge> *adj, vector<bool>& visited, int source, int sink, int c) {
  if (source == sink) {
    return c;
  }
  visited[source] = true;
  for (auto& e : adj[source]) {
    if (!visited[e.v] && e.f < e.w) {
      int d = dfs(adj, visited, e.v, sink, min(c, e.w - e.f));
      if (d > 0) {
        e.f += d;
        for (auto& re : adj[e.v]) {
          if (re.v == source) {
            re.f -= d;
            break;
          }
        }
        return d;
      }
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<edge> adj[n];
  vector<bool> visited(n, false);
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    adj[a].emplace_back(b, w);
    adj[b].emplace_back(a, 0);
  }
  int ans = 0;
  while (true) {
    fill(visited.begin(), visited.end(), false);
    int d = dfs(adj, visited, 0, n - 1, 1e18);
    if (d == 0) {
      break;
    }
    ans += d;
  }
  cout << ans << '\n';
}
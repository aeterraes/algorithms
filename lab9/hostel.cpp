#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, s, f;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin >> s >> f;
  s--;
  f--;
  queue <int> q;
  q.push(s);
  short visited [n];
  for (int i = 0; i < n; i++) {
    visited[i] = 0;
  }
  visited[s] = 1;
  int d[n];
  for (int i = 0; i < n; i++) {
    d[i] = 0;
  }
  int ans = -1;
  while (!q.empty()) {
    int vertex;
    vertex = q.front();
    q.pop();
    if (vertex == f) {
      ans = d[vertex];
      break;
    }
    for (int i : adj[vertex]) {
      if (!visited[i]) {
        q.push(i);
        visited[i] = 1;
        d[i] = d[vertex] + 1;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
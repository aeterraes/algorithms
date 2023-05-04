#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  s--;
  t--;
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    adj[a].emplace_back(b, w);
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  vector<int> d(n, 1e9);
  d[s] = 0;
  pq.emplace(0, s);
  while (!pq.empty()) {
    int v = pq.top().second;
    pq.pop();
    for (auto e : adj[v]) {
      int to = e.first;
      int weight = e.second;
      if (d[v] + weight < d[to]) {
        d[to] = d[v] + weight;
        pq.emplace(d[to], to);
      }
    }
  }
  if (d[t] != 1e9) {
    cout << d[t] << '\n';
  } else {
    cout << -1 << '\n';
  }
  return 0;
}
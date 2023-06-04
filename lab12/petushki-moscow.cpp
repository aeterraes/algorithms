#include <iostream>
#include <vector>

using namespace std;

bool kuhn(int v, vector<vector<int>>& adj, vector<int>& shaded,
          vector<int>& match, vector<bool>& visited) {
  if (visited[v]) {
    return false;
  }
  visited[v] = true;
  for (int i = 0; i < adj[v].size(); i++) {
    int to = adj[v][i];
    if (shaded[to] == -1 || kuhn(shaded[to], adj, shaded, match, visited)) {
      match[v] = to;
      shaded[to] = v;
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> match(n * m + 1, -1), shaded(n * m + 1, -1);
  vector<bool> visited(n * m + 1);
  vector<vector<int>> adj(n * m + 1);
  for (int i = 1; i <= q; i++) {
    int x, y;
    cin >> x >> y;
    int s = (x - 1) * m + y;
    shaded[s] = -1e9;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (((i + j) & 1) == 0 && shaded[(i - 1) * m + j] != -1e9) {
        if (i > 1 && shaded[(i - 2) * m + j] != -1e9) {
          adj[(i - 1) * m + j].push_back((i - 2) * m + j);
        }
        if (i < n && shaded[i * m + j] != -1e9) {
          adj[(i - 1) * m + j].push_back(i * m + j);
        }
        if (j > 1 && shaded[(i - 1) * m + j - 1] != -1e9) {
          adj[(i - 1) * m + j].push_back((i - 1) * m + j - 1);
        }
        if (j < m && shaded[(i - 1) * m + j + 1] != -1e9) {
          adj[(i - 1) * m + j].push_back((i - 1) * m + j + 1);
        }
      }
    }
  }
  bool ok = true;
  while (ok) {
    ok = false;
    fill(visited.begin(), visited.end(), false);
    for (int i = 1; i <= n * m; i++) {
      if (match[i] == -1 && kuhn(i, adj, shaded, match, visited)) {
        ok = true;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n * m; i++) {
    if (match[i] != -1) {
      ans++;
    }
  }
  cout << 2 * ans << '\n';
  return 0;
}
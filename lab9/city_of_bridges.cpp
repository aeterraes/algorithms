#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& adj, short* visited, int v, int prev) {
  visited[v] = 1;
  for (int i : adj[v]) {
    if (!visited[i]) {
      if (dfs(adj, visited, i, v)) {
        return true;
      }
    } else if (i != prev) {
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
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
  short visited [n];
  for (int i = 0; i < n; i++) {
    visited[i] = 0;
  }
  bool flag = false;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      if (dfs(adj, visited, i, -1)) {
        flag = true;
      }
    }
  }
  flag ? cout << "YES" << '\n' : cout << "NO" << '\n';
  return 0;
}
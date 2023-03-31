#include <iostream>
#include <vector>

using namespace std;

void dfs(int u, short* visited, vector<vector<int>>& adj) {
  visited[u] = 1;
  for(int v: adj[u]) {
    if(!visited[v]) {
      dfs(v, visited, adj);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  if (m != n - 1) {
      cout << "NO" << '\n';
      return 0;
  }
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  short visited[n];
  for (int i = 0; i < n; i++) {
    visited[i] = 0;
  }
  dfs(0, visited, adj);
  for(int i = 0; i < n; i++) {
    if(!visited[i]) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  bool flag = true;
  for (int i = 0; i < n; i++) {
    if (adj[i].size() > 2) {
      flag = false;
      break;
    }
  }
  flag ? cout << "YES" << '\n' : cout << "NO" << '\n';
  return 0;
}
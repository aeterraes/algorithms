#include <iostream>
#include <vector>

using namespace std;

vector<int> res;

void dfs(int v, short* visited, vector<vector<int>>& adj) {
  visited[v] = 1;
  for (int u: adj[v]) {
    if (!visited[u]) {
      dfs(u, visited, adj);
    }
  }
  res.push_back(v);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  short visited[n];
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u - 1].push_back(v - 1);
  }
  for (int i = 0; i < n; i++) {
    visited[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs(i, visited, adj);
    }
  }
  reverse(res.begin(), res.end());
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++) {
    ans.emplace_back(res[i], i + 1);
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < n; i++) {
    cout << ans[i].second << " ";
  }
  cout << '\n';
}
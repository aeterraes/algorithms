#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>>& adj, int start, int end, int n) {
  vector<bool> visited(n + 1, false);
  queue<int> q;
  q.push(start);
  visited[start] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (!visited[v]) {
        visited[v] = true;
        q.push(v);
        if (v == end) {
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
  vector<string> ans;
  for (int i = 0; i < q; i++){
    int a, b;
    cin >> a >> b;
    if (a == b) {
      ans.emplace_back("YES");
    } else if (bfs(adj, a, b, n) && bfs(adj, b, a, n)) {
      ans.emplace_back("YES");
    } else {
      ans.emplace_back("NO");
    }
  }
  for (const auto& i : ans) {
    cout << i << '\n';
  }
  return 0;
}
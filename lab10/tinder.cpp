#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& adj, vector<bool>& visited, int start) {
  queue<int> q;
  q.push(start);
  visited[start] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < adj[cur].size(); i++) {
      int next = adj[cur][i];
      if (!visited[next]) {
        visited[next] = true;
        q.push(next);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> adj(n + 1);
  vector<bool> visited (n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<string> ans;
  for (int i = 0; i < q; i++){
    char request;
    int a, b;
    cin >> request >> a >> b;
    if (request == '?') {
      fill(visited.begin(), visited.end(), false);
      bfs(adj, visited, a);
      bool connected_a = visited[b];
      fill(visited.begin(), visited.end(), false);
      bfs(adj, visited, b);
      bool connected_b = visited[a];
      if (connected_a && connected_b) {
        ans.emplace_back("YES");
      } else {
        ans.emplace_back("NO");
      }
    } else {
      int i_a = find(adj[b].begin(), adj[b].end(), a) - adj[b].begin();
      adj[b].erase(adj[b].begin() + i_a);
      int i_b = find(adj[a].begin(), adj[a].end(), b) - adj[a].begin();
      adj[a].erase(adj[a].begin() + i_b);
    }
  }
  for (const auto& i : ans) {
    cout << i << '\n';
  }
  return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<bool> trap(n + 1, false);
  for (int i = 1; i <= n; i++) {
    int c;
    cin >> c;
    if (c)
      trap[i] = true;
  }
  int count = 0;
  vector<bool> visited(n + 1, false);
  vector<int> comp(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      count++;
      queue<int> q;
      q.push(i);
      visited[i] = true;
      while (!q.empty()) {
        int cur = q.front();
        comp[cur] = count;
        q.pop();
        for (int j = 0; j < adj[cur].size(); j++) {
          int next = adj[cur][j];
          if (!visited[next]) {
            visited[next] = true;
            q.push(next);
          }
        }
      }
    }
  }
  vector<bool> trap_comp(n + 1, false);
  for (int i = 1; i <= n; i++) {
    if (trap[i]) {
      trap_comp[comp[i]] = true;
    }
  }
  comp.erase(comp.cbegin());
  trap_comp.erase(trap_comp.cbegin());
  trap_comp.resize(count);
  cout << count << '\n';
  for (const auto& i : comp) {
    cout << i << " ";
  }
  cout << '\n';
  for (const auto& i : trap_comp) {
    cout << i << " ";
  }
  return 0;
}
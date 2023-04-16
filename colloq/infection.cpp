#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int a[n + 1][m + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      a[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    string x;
    cin >> x;
    for (int j = 0; j < m; j++) {
      a[i][j + 1] = x[j] - '0';
    }
  }
  bool visited[n + 1][m + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      visited[i][j] = false;
    }
  }
  queue<pair<int, int>> queue;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 1) {
        queue.push({i, j});
        visited[i][j] = true;
      }
    }
  }
  int sec = 0;
  while (!queue.empty()) {
    int sz = queue.size();
    for (int i = 0; i < sz; i++) {
      int x = queue.front().first;
      int y = queue.front().second;
      queue.pop();
      if (x > 1 && !visited[x - 1][y]) {
        queue.push({x - 1, y});
        visited[x - 1][y] = true;
      }
      if (x < n && !visited[x + 1][y]) {
        queue.push({x + 1, y});
        visited[x + 1][y] = true;
      }
      if (y > 1 && !visited[x][y - 1]) {
        queue.push({x, y - 1});
        visited[x][y - 1] = true;
      }
      if (y < m && !visited[x][y + 1]) {
        queue.push({x, y + 1});
        visited[x][y + 1] = true;
      }
    }
    sec++;
  }
  cout << sec - 1 << '\n';
  return 0;
}
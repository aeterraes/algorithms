#include <iostream>

using namespace std;

void dfs(int i, int j, int n, int m, char** cells, short** visited) {
  if (i < 0 || i >= n || j < 0 || j >= m
      || cells[i][j] == '#' || visited[i][j]) {
    return;
  }
  visited[i][j] = 1;
  dfs(i - 1, j, n, m, cells, visited);
  dfs(i + 1, j, n, m, cells, visited);
  dfs(i, j - 1, n, m, cells, visited);
  dfs(i, j + 1, n, m, cells, visited);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  int m;
  cin >> n >> m;
  char** cells = new char*[n];
  for (int i = 0; i < n; i++) {
    cells[i] = new char[m];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> cells[i][j];
    }
  }
  short** visited = new short*[n];
  for (int i = 0; i < n; i++) {
    visited[i] = new short[m];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      visited[i][j] = 0;
    }
  }
  int c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (cells[i][j] == '.' && !visited[i][j]) {
        c++;
        dfs(i, j, n, m, cells, visited);
      }
    }
  }
  cout << c << '\n';
  delete [] cells;
  delete [] visited;
  return 0;
}
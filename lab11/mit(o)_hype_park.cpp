#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int d[n + 1][n + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      i == j ? d[i][j] = 0 : d[i][j] = 1e9;
    }
  }
  for (int i = 1; i <= m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    d[a][b] = w;
    d[b][a] = w;
  }
  int ans = 0;
  for (int p = 1; p <= n; p++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][p] + d[p][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int mx = 0;
    for (int j = 1; j <= n; j++) {
      if (d[i][j] > mx && d[i][j] != 1e9) {
        mx = d[i][j];
      }
    }
    if (mx > ans) {
      ans = mx;
    }
  }
  cout << ans << '\n';
  return 0;
}
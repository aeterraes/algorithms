#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  int d[n + 1][n + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      i == j ? d[i][j] = 0 : d[i][j] = 1e6 + 2;
    }
  }
  for (int i = 1; i <= m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    d[a][b] = w;
  }
  int q;
  vector<pair<int, int>> req;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    req.emplace_back(a, b);
  }
  for (int p = 1; p <= n; p++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
          if (d[i][p] != 1e6 + 2 && d[p][j] != 1e6 + 2
              && i != j && i != p && j != p
              && abs(p - i) <= k && abs(p - j) <= k) {
            d[i][j] = min(d[i][j], d[i][p] + d[p][j]);
          }
        }
      }
    }
  
  for (int i = 0; i < q; i++) {
    if (d[req[i].first][req[i].second] != 1e6 + 2) {
      cout << d[req[i].first][req[i].second] << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
}
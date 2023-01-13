#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    for (int j = 0; j < m; j++) {
      a[i][j] = x[j] - '0';
      if (a[i][j] == 5) {
        a[i][j] = 1;
      } else {
        a[i][j] = 0;
      }
    }
  }
  int mx = 0;
  int a1 = 0;
  int b1 = 0;
  if (m == 1 || n == 1) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 1) {
          mx = 1;
        }
        if (a[i][j] == mx) {
          a1 = i;
          b1 = j;
        }
      }
    }
    cout << mx << " " << a1 - mx + 2 << " " << b1 - mx + 2;
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] && i && j) {
          a[i][j] = min({a[i - 1][j], a[i - 1][j - 1], a[i][j - 1]}) + 1;
        }
        if (a[i][j] > mx) {
            mx = a[i][j];
          }
          if (a[i][j] == mx) {
            a1 = i;
            b1 = j;
          }
      }
    }
    cout << mx << " " << a1 - mx + 2 << " " << b1 - mx + 2;
  }
  return 0;
}
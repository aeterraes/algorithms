#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct dsu {
  vector<int> parent;
  vector<int> r;
  dsu(int n) {
    parent.resize(n + 1);
    r.resize(n, 0);
    for (int i = 1; i <= n; i++) {
      parent[i] = i;
    }
  }
  int find(int x) {
    if (x != parent[x]) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }
  void unite(int x, int y) {
    int _x = find(x);
    int _y = find(y);
    if (_x == _y) {
      return;
    }
    if (r[_x] == r[_y]) {
      r[_x]++;
    }
    if (r[_x] < r[_y]) {
      parent[_x] = _y;
    } else {
      parent[_y] = _x;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj;
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    adj.push_back({w, a, b});
  }
  sort(adj.begin(), adj.end());
  dsu d = dsu(n);
  int ans = 0;
  vector<int> mst;
  for (auto e : adj) {
    if (d.find(e[1]) != d.find(e[2])) {
      d.unite(e[1], e[2]);
      ans += e[0];
      mst.push_back(e[0]);
    }
  }
  int ans_second = 1e9;
  for (int i = 0; i < n - 1; i++) {
    dsu d_second = dsu(n);
    int current = 0;
    int count = 0;
    for (auto e : adj) {
      if (e[0] == mst[i]) {
        continue;
      }
      if (d_second.find(e[1]) != d_second.find(e[2])) {
        d_second.unite(e[1], e[2]);
        current += e[0];
        count++;
      }
    }
    if (count == n - 1) {
      ans_second = min(ans_second, current);
    }
  }
  cout << ans << " " << ans_second << '\n';
  return 0;
}
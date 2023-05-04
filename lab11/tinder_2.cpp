#include <iostream>
#include <vector>

using namespace std;

struct u {
  int op = 0;
  int a = 0;
  int b = 0;
};

struct dsu {
  vector<int> parent;
  vector<u> info;
  vector<int> r;
  dsu(int n, int q) {
    parent.resize(n + 1);
    info.resize(q);
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
  int n, m, q;
  cin >> n >> m >> q;
  dsu d(n, q);
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }
  vector<string> ans;
  for (int i = 0; i < q; i++) {
    char request;
    int a, b;
    cin >> request >> a >> b;
    a--;
    b--;
    d.info[i].a = a;
    d.info[i].b = b;
    if (request == '?') {
      d.info[i].op = 1;
    } else {
      adj[a].erase(remove(adj[a].begin(), adj[a].end(), b), adj[a].end());
      adj[b].erase(remove(adj[b].begin(), adj[b].end(), a), adj[b].end());
    }
  }
  int res[q];
  for (int i = 0; i < q; i++) {
    res[i] = 0;
  }
  for (int i = 0; i < adj.size(); i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      d.unite(adj[i][j], i);
    }
  }
  for (int i = q - 1; i >= 0; i--) {
    if (d.info[i].op) {
      res[i] = (d.find(d.info[i].a) == d.find(d.info[i].b));
    } else {
      d.unite(d.info[i].a, d.info[i].b);
    }
  }
  for (int i = 0; i < q; i++) {
    if (d.info[i].op) {
      if (res[i]) {
        ans.emplace_back("YES");
      } else {
        ans.emplace_back("NO");
      }
    }
  }
  for (const auto& i : ans) {
    cout << i << '\n';
  }
  return 0;
}
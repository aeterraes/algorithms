#include <iostream>
#include <vector>

using namespace std;

struct node {
  int value;
  int left;
  int right;
  int h = 1;
  int b = 0;
};

vector <node> a;

void insert(int nd) {
  if (a[nd].left != 0 || a[nd].right != 0) {
    insert(a[nd].left);
    insert(a[nd].right);
    a[nd].h = 1 + max(a[a[nd].left].h, a[a[nd].right].h);
    a[nd].b = a[a[nd].right].h - a[a[nd].left].h;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  a.push_back({0, 0, 0, 0, 0});
  int k, l, r;
  for (int i = 0; i < n; i++) {
    cin >> k >> l >> r;
    a.push_back({k, l, r, 1, 0});
  }
  insert(1);
  for (int i = 1; i <= n; i++) {
    cout << a[i].b << '\n';
  }
  return 0;
}

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  unordered_set<int> a;
  unordered_set<int> b;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.insert(x);
  }
  for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      b.insert(x);
  }
  if (a == b) {
      cout << "YES" << '\n';
  } else {
      cout << "NO" << '\n';
  }
  return 0;
}
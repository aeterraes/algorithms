#include <iostream>
#include <vector>

using namespace std;

int hash_func(int key) {
  return key + 10000019;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> count(10100021);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int diff = a[i] - i;
    int hash = hash_func(diff);
    ans += count[hash];
    count[hash]++;
  }
  cout << ans << '\n';
  return 0;
}
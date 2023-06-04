#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     string s;
     cin >> s;
     int n = s.size();
     vector<int> prf(n);
     prf[0] = 0;
     for (int i = 1; i < n; i++) {
         int pos = prf[i - 1];
         while (pos > 0 && s[i] != s[pos]) {
             pos = prf[pos - 1];
         }
         if (s[i] == s[pos]) {
             pos++;
         }
         prf[i] = pos;
     }
     for (const auto& i : prf) {
         cout << i << " ";
     }
     cout << '\n';
    return 0;
}
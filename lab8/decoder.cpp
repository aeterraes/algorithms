#include <iostream>
#include <vector>

using namespace std;

vector<string> decode(vector<string>& input, int n) {
  vector <string> res;
  for (int i = 0; i < n; i++) {
    int j, mistake = 0;
    int b = 1;
    int len = input[i].size();
    for (j = 0; j < len; j++) {
      if (input[i][j] == '1')
        mistake ^= j + 1;
    }
    if (mistake) {
      input[i][mistake - 1] ^= '0' ^ '1';
    }
    string a;
    for (j = 0; j < len; j++) {
      if (j + 1 == b) {
        b <<= 1;
      } else {
        a += input[i][j];
      }
    }
    res.push_back(a);
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<string> input;
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    input.push_back(x);
  }
  vector<string> res = decode(input, n);
  for (int i = 0; i < n; i++) {
    cout << res[i] << '\n';
  }
  return 0;
}
#include <iostream>
#include <vector>

using namespace std;

void radix(vector<string>& a, int n, int m, int num, int k) {
    vector<int> c(num);
    vector<string> b(n);
    int f = 0;
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < num; j++) {
            c[j] = 0;
        }
        for (int j = 0; j < n; j++) {
            int d = a[j].at(i) + 1;
            c[d]++;
        }
        int count = 0;
        for (int j = 0; j < num; j++) {
            int tmp = c[j];
            c[j] = count;
            count += tmp;
        }
        for (int j = 0; j < n; j++) {
            int d = a[j].at(i) + 1;
            b[c[d]] = a[j];
            c[d]++;
        }
        for (int j = 0; j < n; j++) {
            a[j] = b[j];
        }
        f++;
        if (f == k) {
            for (int p = 0; p < n; p++) {
                cout << a[p] << '\n';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;;
    vector<string> a;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        a.push_back(x);
    }
    int ascii_cnt = 257;
    radix(a, n, m, ascii_cnt, k);
    return 0;
}
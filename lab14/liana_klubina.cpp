#include <iostream>
#include <vector>

using namespace std;

const int p = 31;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    string t;
    cin >> t;
    vector<unsigned long long> pows(n + 1);
    pows[0] = 1;
    for (int i = 0; i < n; i++) {
        pows[i + 1] = pows[i] * p;
    }
    vector<unsigned long long> h(n + 1);
    h[0] = 0;
    for (int i = 0; i < n; i++) {
        h[i + 1] = t[i] + h[i] * p;
    }
    int count = 0;
    for (int q = 0; q < m; q++) {
        int i, j, k;
        cin >> i >> j >> k;
        i--, j--;
        unsigned long long h1 = h[i + k] - h[i] * pows[k];
        unsigned long long h2 = h[j + k] - h[j] * pows[k];
        if (h1 == h2) {
            count++;
        }
    }
    cout << count << '\n';
    return 0;
}
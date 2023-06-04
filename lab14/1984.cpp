#include <iostream>
#include <vector>

using namespace std;

const int p = 31;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string t, x;
    cin >> t >> x;
    int n = t.size();
    int m = x.size();
    if (m > n) {
        cout << 0 << '\n';
        return 0;
    }
    vector<long long> pows(max(n, m));
    pows[0] = 1;
    for (int i = 1; i < pows.size(); i++) {
        pows[i] = pows[i - 1] * p;
    }
    vector<long long> ht(n);
    ht[0] = (t[0] - 'a' + 1);
    for (int i = 1; i < n; i++) {
        ht[i] = (t[i] - 'a' + 1) * pows[i] + ht[i - 1];
    }
    long long hx = 0;
    for (int i = 0; i < m; i++) {
        hx += (x[i] - 'a' + 1) * pows[i];
    }
    vector<int> ans;
    int cnt = 0;
    int j;
    long long cur = ht[m - 1];
    if (cur == hx) {
        ans.push_back(0);
        cnt++;
    }
    for (int i = 1; i + m - 1 < n; i++) {
        cur = ht[i + m - 1] - ht[i - 1];
        if (cur == hx * pows[i]) {
            for (j = 0; j < m; j++) {
                if (t[i + j] != x[j]) {
                    break;
                }
            }
            if (j == m) {
                ans.push_back(i);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    for (const auto& i : ans) {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}
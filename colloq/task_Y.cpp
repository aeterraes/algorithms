#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int s, n;
    cin >> s >> n;
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++){
        int a, b;
        std::cin >> a >> b;
        p.emplace_back(a, b);
    }
    sort(p.begin(), p.end());
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (s <= p[i].first) {
            ok = false;
            break;
        } else {
            s += p[i].second;
        }
    }
    if (ok) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}
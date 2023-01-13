#include <iostream>

int left (const int* a, int k, int l, int r) {
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (a[m] < k) {
            l = m;
        } else {
            r = m;
        }
    }
    return a[r] == k ? r + 1 : -1;
}
int right (const int* a, int k, int l, int r) {
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (a[m] <= k) {
            l = m;
        } else {
            r = m;
        }
    }
    return a[l] == k ? l + 1 : -1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::cin >> m;
    int* b = new int[m];
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
        std::cout << left(a, b[i], -1, n) << " " << right(a, b[i], -1, n) << '\n';
    }
    return 0;
}
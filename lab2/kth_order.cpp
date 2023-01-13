#include <iostream>

int find_k_order(int*a, int l, int r, int k) {
    int p = a[(l + r) / 2];
    int i = l;
    int j = r;
    while (i <= j) {
        while (a[i] < p) {
            i++;
        }
        while (a[j] > p) {
            j--;
        }
        if (i <= j) {
            std::swap(a[i++], a[j--]);
        }
    }
    if (l <= k && k <= j) {
        return find_k_order(a, l, j, k);
    }
    if (i <= k && k <= r) {
        return find_k_order(a, i, r, k);
    }
    return a[k];
}

int main() {
    int n, k, a, b, c;
    std::cin >> n >> k;
    int* v = new int[n];
    std::cin >> a >> b >> c >> v[0] >> v[1];
    for (int i = 2; i < n; i++) {
        v[i] = a * v[i - 2] + b * v[i - 1] + c;
    }
    std::cout << find_k_order(v, 0, n - 1, k - 1);
    return 0;
}

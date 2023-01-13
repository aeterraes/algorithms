#include <iostream>

using namespace std;

int left(int i) {
    return 2 * i + 1;
}

int right(int i){
    return 2 * i + 2;
}

void heapify(int a[], int n, int i) {
    int mx = i;
    int l = left(i);
    int r = right(i);
    if (l < n && a[l] > a[mx]) {
        mx = l;
    }
    if (r < n && a[r] > a[mx]) {
        mx = r;
    }
    if (mx != i) {
        swap(a[i], a[mx]);
        heapify(a, n, mx);
    }
}

void build_heap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
}

void heapsort(int a[], int n) {
    build_heap(a, n);
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int* a = new int [n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    heapsort(a, n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
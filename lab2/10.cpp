#include <iostream>
#include <vector>

void antiquicksort(std::vector<int>& a, int n) {
    for (int i = 2; i < n; i++) {
        std::swap(a[i], a[i / 2]);
    }
};
int main() {
    std::vector <int> a;
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        a.push_back(i);
    }
    antiquicksort(a, n);
    for (int i = 0; i < n; i++){
        std::cout << (a[i]) << " ";
    }
    return 0;
}
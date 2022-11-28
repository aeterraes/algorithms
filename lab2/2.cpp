#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>& a, int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        while (j >= 0 && (a[j] > a[j + 1])) {
            std::swap(a[j], a[j + 1]);
            j--;
        }
    }
}
void print(std::vector<int>a, int n){
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> a;
    for (int i = 0; i < n; i++){
        int x;
        std::cin >> x;
        a.push_back(x);
    }
    insertion_sort(a, n);
    print(a, n);
    return 0;
}
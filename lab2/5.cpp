#include <iostream>
#include <vector>

void insertion_sort(std::vector<std::pair<int, int>>& p, int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        while (j >= 0 && (p[j].second < p[j + 1].second)) {
            std::swap(p[j], p[j + 1]);
            j--;
        }
    }
}

struct cmp {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        if (left.second == right.second) {
            return left.first < right.first;
        }
        return left.second > right.second;
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> p;
    for (int i = 0; i < n; i++){
        int a, b;
        std::cin >> a >> b;
        p.emplace_back(a, b);
    }
    insertion_sort(p, n);
    sort(p.begin(), p.end(), cmp());
    for (int i = 0; i < n; i++){
        std::cout << p[i].first << " "
             << p[i].second << std::endl;
    }
    return 0;
}
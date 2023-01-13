#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> p;
    for (int i = 0; i < n; i++){
        int a, b;
        std::cin >> a >> b;
        p.emplace_back(a, b);
    }
    std::sort(p.begin(), p.end());
    int start = p[0].first;
    int end = p[0].second;
    int cnt =  0;
    for (int i = 1; i < n; i++) {
        if (p[i].first > end) {
            cnt += (end + 1) - start;
            start = p[i].first;
            end = p[i].second;
        } else {
            end = std::max(p[i].second, end);
        }
    }
    cnt += (end + 1) - start;
    std::cout << cnt << std::endl;
    return 0;
}

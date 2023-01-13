#include <iostream>
#include <vector>

int main() {
    int n, m, k;
    std::cin >> n >> m;
    int raft = n * m;
    std::vector <int> capacity;
    for (int i = 0; i < raft; i++) {
        int x;
        std::cin >> x;
        capacity.push_back(x);
    }
    std::cin >> k;
    std::vector <int> weight;
    for (int i = 0; i < k; i++) {
        int y;
        std::cin >> y;
        weight.push_back(y);
    }
    std::sort(capacity.begin(), capacity.end());
    std::sort(weight.begin(), weight.end());
    int cnt = 0, first = 0, second = 0;
    while ((first < raft) && (second < k)) {
        if (weight[second] <= capacity[first]) {
            cnt++;
            first++;
            second++;
        } else {
            first++;
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}
